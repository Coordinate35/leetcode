# include<stdio.h>

int firstMissingPositive(int* nums, int numsSize) 
{
	int i, absolution;
	for (i = 0; i < numsSize; i++)
	{
		if ((nums[i] < 1) || (nums[i] > numsSize))
		{
			nums[i] = numsSize + 1;
		}
	}

	for (i = 0; i < numsSize; i++)
	{
		absolution = nums[i] > 0 ? nums[i] : -nums[i];
		if ((0 < absolution) && (numsSize >= absolution))
		{
			nums[absolution - 1] = nums[absolution - 1] > 0 ? -nums[absolution - 1] : nums[absolution - 1];
		}
	}

	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] > 0)
		{
			return i + 1;
		}
	}

	return numsSize + 1;
}

int main()
{
	int numsSize, i, first_missing_positive;
	int nums[20];
	scanf_s("%d", &numsSize);
	for (i = 0; i < numsSize; i++)
	{
		scanf_s("%d", nums + i);
	}

	first_missing_positive = firstMissingPositive(nums, numsSize);
	printf("%d", first_missing_positive);
	getchar();
	getchar();
	return 0;
}