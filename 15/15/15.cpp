#include <stdio.h>
#include <stdlib.h>

void exchange(int *a, int *b)
{
	int buffer;
	buffer = *a;
	*a = *b;
	*b = buffer;
}

void quick_sort(int* nums, int start, int end)
{
	int i;
	int index, x;
	int position = start;
	if (start >= end)
	{
		return;
	}
	index = rand();
	index = index % (end - start) + start;
	x = nums[index];
	for (i = start; i <= end; i++)
	{
		if (nums[i] < x)
		{
			if (index == position)
			{
				index = i;
			}
			exchange(nums + position, nums + i);
			position += 1;
		}
	}
	exchange(nums + index, nums + position);
	quick_sort(nums, start, position - 1);
	quick_sort(nums, position + 1, end);
}

int find_tail(int* nums, int middle_edge, int tail_edge, int tail_num)
{
	int index;
	int finded = 0;
	int distance;
	distance = tail_edge - middle_edge;
	distance = distance > 0 ? distance : (-1) * distance;
	while (distance > 1)
	{
		index = (tail_edge + middle_edge) / 2;
		if (nums[index] > tail_num)
		{
			tail_edge = index;
			distance = tail_edge - middle_edge;
		}
		else if (nums[index] < tail_num)
		{
			middle_edge = index;
			distance = tail_edge - middle_edge;
		}
		else
		{
			finded = 1;
			return finded;
		}
	}
	return finded;
}

int** threeSum(int* nums, int numsSize, int* returnSize) 
{
	int fore, middle, tail_num, target = 0;
	int fore_edge, middle_edge, tail_edge;
	int find_result;
	int size = 0;
	int *one_list;
	int **result = NULL;
	result = (int**)malloc(sizeof(int*));
	if (3 > numsSize)
	{
		return result;
	}
	fore_edge = numsSize - 2;
	middle_edge = numsSize - 1;
	tail_edge = numsSize;
	*returnSize = 0;
	quick_sort(nums, 0, numsSize - 1);
	for (fore = 0; fore < fore_edge; fore++)
	{
		for (middle = fore + 1; middle < middle_edge; middle++)
		{
			tail_num = target - nums[middle] - nums[fore];
			if (tail_num < nums[middle])
			{
				find_result = 0;
			}
			else
			{
				find_result = find_tail(nums, middle, tail_edge, tail_num);
			}
			if (1 == find_result)
			{
				result = (int**)realloc(result, sizeof(int*) * (size + 1));
				one_list = (int*)malloc(3 * sizeof(int));
				one_list[0] = nums[fore];
				one_list[1] = nums[middle];
				one_list[2] = tail_num;
				result[size] = one_list;
				//printf("%d %d\n", size, one_list);
				//printf("%d %d %d\n", result[size][0], result[size][1], result[size][2]);
				size += 1;
				while (nums[fore + 1] == nums[fore])
				{
					fore++;
				}
				while (nums[middle + 1] == nums[middle])
				{
					middle++;
				}
			}
		}
	}
	*returnSize = size;
	return result;
}

int main()
{
	int nums[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	int numsSize = 15;
	int returnSize = 0;
	int **result;
	result = threeSum(nums, numsSize, &returnSize);
	//quick_sort(nums, 0, numsSize - 1);
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
	}
	/*
	for (int i = 0; i < numsSize; i++)
	{
		printf("%d ", nums[i]);
	}
	*/
	system("pause");
	return 0;
}
