#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    int i, j;
    int *result = (int *)malloc(2 * sizeof(int));
    
    for (i = 0; i < numsSize - 1; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target)
            {
                *result = i;
                *(result + 1) = j;
                return result;
            }
        }
    }
    return result;
}

int main(void) {
	int nums[4] = {2, 7, 11, 15};
	int *result;
	result = twoSum(nums, 4, 9);
	printf("%d, %d\n", *result, *(result+1));
	return 0;
}
