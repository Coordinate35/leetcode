# include<stdio.h>
# include<stdlib.h>
# include<string.h>

void quicksort(char** numbers, int numsSize, int start)
{
	int x, i, partition;
	char *buffer;
	x = start;
	partition = start;
	for (i = 0; i < numsSize; i++)
	{
		if (strcmp(numbers[i], numbers[x]) < 0)
		{
			buffer = numbers[partition];
			numbers[partition] = numbers[i];
			numbers[i] = numbers[partition];
			partition++;
		}
	}
	buffer = numbers[partition];
	numbers[partition] = numbers[i];
	numbers[i] = buffer;
	if (partition > start)
	{
		quicksort(numbers, partition - start, start);
	}
	if (partition < start + numsSize - 1)
	{
		quicksort(numbers, partition + 1, start + numsSize - 1 - partition);
	}
}

void num2str(int num, char* str)
{
	int place, ten_pow_place;
	place = 0;
	ten_pow_place = 1;
	while (0 != num / ten_pow_place)
	{
		ten_pow_place *= 10;
		place++;
	}
	ten_pow_place /= 10;
	str = (char*)calloc(place, sizeof(char));
	str[place - 1] = '\0';

}

char* largestNumber(int* nums, int numsSize) 
{
	int i, length, j, sub_length, position;
	char **numbers;
	char *largest_number;
	length = 0;
	numbers = (char**)calloc(numsSize, sizeof(char*));
	for (i = 0; i < numsSize; i++)
	{
		_itoa_s(nums[i], numbers[i], 10);
		length += strlen(numbers[i]);
	}
	quicksort(numbers, numsSize, 0);
	largest_number = (char*)calloc(length, sizeof(char));
	position = 0;
	for (i = 0; i < numsSize; i++)
	{
		sub_length = strlen(numbers[i]);
		for (j = 0; j < sub_length; j++)
		{
			largest_number[position] = numbers[i][j];
			position++;
		}
	}
	return largest_number;
}

int main()
{
	int i, numsSize;
	int nums[10];
	char *largest_number;
	scanf_s("%d", numsSize);
	for (i = 0; i < numsSize; i++)
	{
		scanf_s("%d", nums + i);
	}
	largest_number = largestNumber(nums, numsSize);
	puts(largest_number);
	return 0;
}
