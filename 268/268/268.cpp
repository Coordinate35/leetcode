# include<stdio.h>
# include<stdlib.h>

int missingNumber(int* nums, int numsSize)
{
	int expected_sum, i, sum;
	expected_sum = (1 + numsSize) * numsSize / 2;
	sum = 0;
	for (i = 0; i < numsSize; i++)
	{
		sum += nums[i];
	}
	return (expected_sum - sum);
}

int main()
{
	int nums[20];
	int numsSize, i, answer;
	scanf_s("%d", &numsSize);
	for (i = 0; i < numsSize; i++)
	{
		scanf_s("%d", nums + i);
	}
	answer = missingNumber(nums, numsSize);
	printf("%d", answer);
	getchar();
	getchar();
	return 0;
}