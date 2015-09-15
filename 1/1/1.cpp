/**
* Note: The returned array must be malloced, assume caller calls free().
*/

#include<stdio.h>
#include<stdlib.h>

/*
void quicksort(int* index, int* nums, int numsSize, int left, int right)
{
	int i, j, x, buffer;
	i = left;
	j = left;
	buffer = 0;
	x = nums[left];
	for (i = left; i <= right; i++)
	{
		if (nums[i] < x)
		{
			buffer       = nums[j];
			nums[j]      = nums[i];
			nums[i]      = nums[j + 1];
			nums[j + 1]  = buffer;

			buffer       = index[j];
			index[j]     = index[i];
			index[i]     = index[j + 1];
			index[j + 1] = buffer;

			j++;
		}
	}
	if (j - left > 1)
	{
		quicksort(index, nums, j - left, left, j - 1);
	}
	if (right - j > 0)
	{
		quicksort(index, nums, right - j, j + 1, right);
	}
}

int* twoSum(int* nums, int numsSize, int target)
{
	int* result;
	int bound, i, subtarget, found, lower_bound, upper_bound, middle, buffer;
	int* index;

	index = (int*)malloc(numsSize*sizeof(int));
	for (i = 0; i < numsSize; i++)
	{
		index[i] = i + 1;
	}

	quicksort(index, nums, numsSize, 0, numsSize - 1);
	result = (int*)malloc(2 * sizeof(int));
	bound  = target / 2;
	i      = 0;
	found  = 0;
	while ((nums[i] <= bound) && (i < numsSize))
	{
		result[0]   = index[i];
		subtarget   = target - nums[i];
		if (subtarget != nums[i])
		{
			lower_bound = 0;
			upper_bound = numsSize - 1;
			while (lower_bound <= upper_bound)
			{
				middle = (lower_bound + upper_bound) / 2;
				if (subtarget == nums[middle])
				{
					result[1] = index[middle];
					found = 1;
				}
				else if (subtarget < nums[middle])
				{
					upper_bound = middle - 1;
				}
				else if (subtarget > nums[middle])
				{
					lower_bound = middle + 1;
				}

				if (1 == found)
				{
					break;
				}
			}
		}
		else if (nums[i + 1] == subtarget)
		{
			found     = 1;
			result[1] = index[i + 1];
		}
		if (1 == found)
		{
			break;
		}

		i++;
	}

	if (result[1] < result[0])
	{
		buffer    = result[1];
		result[1] = result[0];
		result[0] = buffer;
	}

	return result;
}
*/

int* twoSum(int* nums, int numsSize, int target)
{
	int i, buffer, key, answer_number, j;
	int *result, *number, *index;

	index = (int*)malloc(100000 * sizeof(int));
	number = index + 50000;

	result = (int*)malloc(2 * sizeof(int));
	for (i = -50000; i < 50000; i++)
	{
		number[i] = 0;
	}

	for (i = 0; i < numsSize; i++)
	{
		number[nums[i]] = i + 1;
	}

	for (i = -50000; i < 50000; i++)
	{
		if ((number[i]) && (number[target - i]))
		{
			if (i != target - i)
			{
				result[0] = number[i];
				result[1] = number[target - i];
				break;
			}
			else
			{
				key           = i;
				answer_number = 0;
				for (j = 0; j < numsSize; j++)
				{
					if (nums[j] == key)
					{
						result[answer_number] = j + 1;
						answer_number++;
					}
				}
				if (answer_number == 2)
				{
					break;
				}
			}
		}
	}

	if (result[1] < result[0])
	{
		buffer    = result[1];
		result[1] = result[0];
		result[0] = buffer;
	}

	return result;
}

int main()
{
	int numsSize, i, target;
	int nums[10];
	int *result;

	scanf_s("%d%d", &numsSize, &target, 2 * sizeof(int));
	for (i = 0; i < numsSize; i++)
	{
		scanf_s("%d", nums + i, sizeof(int));
	}

	result = twoSum(nums, numsSize, target);
	printf("%d %d", result[0], result[1]);

	system("pause");
	return 0;
}