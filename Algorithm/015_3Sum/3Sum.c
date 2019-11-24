#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int inc(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	int i;
	int sum, left, right;
	int** res = NULL;
	int** newRes;
	int* newReturnColumnSizes;
	int mallocSize;
	int oldMallocSize;


	*returnSize = 0;
	*returnColumnSizes = NULL;
	qsort(nums, numsSize, sizeof(int), inc);
	
	mallocSize = 1;
	res = (int**)malloc(sizeof(int *) * mallocSize);
	*returnColumnSizes = (int*)malloc(sizeof(int) * mallocSize);
	for (i = 0; i < numsSize - 2; i++)
	{
		while ((i < numsSize - 2) && (i > 0) && (nums[i] == nums[i - 1]))  //remove duplication
			i++;
		left = i + 1;
		right = numsSize - 1;
		sum = -nums[i];

		while (left < right)
		{
			int tmp = nums[left] + nums[right];
			if (tmp > sum)
				right--;
			else if (tmp < sum)
				left++;
			else {
				if (!*returnSize || (*returnSize && (nums[i] != res[*returnSize - 1][0] || nums[left] != res[*returnSize - 1][1]))) {
					(*returnSize)++;
					if (mallocSize < *returnSize)	// beaause realloc cause MLE, so malloc, memcpy and free
					{
						oldMallocSize = mallocSize;
						mallocSize *= 2;
						newRes = (int**)malloc(sizeof(int*) * mallocSize);
						newReturnColumnSizes = (int*)malloc(sizeof(int) * mallocSize);
						memcpy(newRes, res, oldMallocSize * sizeof(int*));
						memcpy(newReturnColumnSizes, *returnColumnSizes, oldMallocSize * sizeof(int));
						free(res);
						free(*returnColumnSizes);
						res = newRes;
						*returnColumnSizes = newReturnColumnSizes;
					}
					(*returnColumnSizes)[*returnSize - 1] = 3;
					res[*returnSize - 1] = (int*)malloc(sizeof(int) * 3);
					res[*returnSize - 1][0] = nums[i];
					res[*returnSize - 1][1] = nums[left];
					res[*returnSize - 1][2] = nums[right];
				}
				left++;
			}
		}
	}

	if (*returnSize == 0) {
		free(res);
		free(*returnColumnSizes);
		res = NULL;
		*returnColumnSizes = NULL;
	}
	return res;
}
