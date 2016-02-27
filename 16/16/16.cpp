#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int threeSumClosest(int* nums, int numsSize, int target) 
{
	int fore, middle, tail, distance, closest_sum, middle_tail_sum, object, min_distance;
	int fore_edge;
	fore_edge = numsSize - 2;
	min_distance = INT_MAX;
	quick_sort(nums, 0, numsSize - 1);
	for (fore = 0; fore < fore_edge; fore++)
	{
		middle = fore + 1;
		tail = numsSize - 1;
		while (middle < tail)
		{
			object = target - nums[fore];
			middle_tail_sum = nums[middle] + nums[tail];
			distance = abs(target - middle_tail_sum - nums[fore]);
			if (distance < min_distance)
			{
				min_distance = distance;
				closest_sum = nums[fore] + middle_tail_sum;
			}
			if (middle_tail_sum > object)
			{
				tail -= 1;
			}
			else if (middle_tail_sum < object)
			{
				middle += 1;
			}
			else
			{
				return target;
			}
		}
		while (nums[fore + 1] == nums[fore])
		{
			fore += 1;
		}
	}
	return closest_sum;
}

int main()
{
	int nums[] = {0, 0, 0};
	int numsSize = 3;
	int target = 1;
	int closest_sum;
	closest_sum = threeSumClosest(nums, numsSize, target);
	printf("%d\n", closest_sum);
	system("pause");
	return 0;
}