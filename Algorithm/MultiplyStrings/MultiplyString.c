/** Given two non-negative integers num1 and num2 represented as strings,
 *  return the product of num1 and num2, also represented as a string.
 */
#include <stdio.h>
#include <string.h>

#define MAX_LEN  110

extern char gResult[MAX_LEN * 2] = {'\0'};

char charToNum(char ch) {
	return (char)(ch - '0');
}

void bitMul(char value, char *arr, size_t len, size_t pos) {
	char v1, v2, product, r1, r2;
	int i;
	size_t check;

	v1 = charToNum(value);
	for (i = len -1; i >= 0; i--, pos++) {
		v2 = charToNum(arr[i]);
		product = v1 * v2;
		r1 = product % 10;
		r2 = product / 10;
		gResult[pos] += r1;
		gResult[pos + 1] += r2;
		for (check = pos; gResult[check] >= 10; check++)
		{
			r1 = gResult[check] % 10;
			r2 = gResult[check] / 10;
			gResult[check] = r1;
			gResult[check + 1] += r2;
		}
	}
}

void reverse(char *arr, size_t len) {
	size_t start = 0, last = len -1;
	char tmp;
	while (start < last) {
		tmp = arr[start];
		arr[start] = arr[last] + '0';
		arr[last] = tmp + '0';
		start++;
		last--;
	} 
	if (len % 2) {
		arr[start] += '0';
	}
}

char* multiply(char* num1, char* num2) {
	size_t len1, len2, minLen, maxLen, pos;
	char *multiplicand, *multiplier;
	int i;

	memset(gResult, 0x00, MAX_LEN * 2);
	len1 = strlen(num1);
	len2 = strlen(num2);
	if (len1 >= len2) {
		multiplicand = num1;
		multiplier = num2;
		minLen = len2;
		maxLen = len1;
	} else {
		multiplicand = num2;
		multiplier = num1;
		minLen = len1;
		maxLen = len2;
	}

	for (i = minLen - 1, pos = 0; i >= 0; i--, pos++) {
		bitMul(multiplier[i], multiplicand, maxLen, pos);
	}

	//calculate the len of result
	maxLen = MAX_LEN * 2 - 1;
	while (gResult[maxLen] == '\0') {
		if (maxLen == 0) {
			gResult[0] = '0';
			return gResult;
		}
		maxLen--;
	}
	maxLen++;
	
	//last turn arount the result and transfer to char
	reverse(gResult, maxLen);

	return gResult;
}