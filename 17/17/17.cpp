#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
void strrev(char *s)
{
	char* h = s;
	char* t = s;
	char buffer;
	while ('\0' != *t)
	{
		t += 1;
	}
	t -= 1;
	while (h < t)
	{
		buffer = *h;
		*h = *t;
		*t = buffer;
	}
}
*/
char* get_current_possible_char(char num)
{
	char* result, *buffer;
	result = (char*)malloc(4 * sizeof(char));
	char s2[] = "abc";
	char s3[] = "def";
	char s4[] = "ghi";
	char s5[] = "jkl";
	char s6[] = "mno";
	char s7[] = "pqrs";
	char s8[] = "tuv";
	char s9[] = "wxyz";
	switch (num)
	{
	case '2': buffer = s2; break;
	case '3': buffer = s3; break;
	case '4': buffer = s4; break;
	case '5': buffer = s5; break;
	case '6': buffer = s6; break;
	case '7': buffer = s7; break;
	case '8': buffer = s8; break;
	case '9': buffer = s9; break;
	}
	strcpy(result, buffer);
	return result;
}

char** letterCombinations(char* digits, int* returnSize)
{
	int length, i, current_string_length, next_size, j, p, buffer_length;
	char **result = NULL;
	char *current_possible_char;
	length = strlen(digits);
	*returnSize = 0;
	if (0 == length)
	{
		return result;
	}
	*returnSize = 1;
	result = (char**)malloc(sizeof(char*));
	result[0] = NULL;
	for (i = length - 1; i >= 0; i--)
	{
		current_possible_char = get_current_possible_char(digits[i]);
		current_string_length = strlen(current_possible_char);
		next_size = current_string_length * (*returnSize);
		result = (char**)realloc(result, (*returnSize) * sizeof(char*));
		p = (1 == *returnSize) ? 0 : *returnSize + 1;
		while (current_string_length > 1)
		{
			current_string_length -= 1;
			for (j = 0; j < *returnSize; j++)
			{
				//buffer_length = current_string_length == strlen(current_possible_char) - 1 ? 0 : strlen(result[j]);
				buffer_length = strlen(current_possible_char);
				if (current_string_length == strlen(current_possible_char) - 1)
				{
					buffer_length = 0;
				}
				else
				{
					buffer_length = strlen(result[j]);
				}
				result[p] = (char*)malloc((buffer_length + 2) * sizeof(char));
				result[p][0] = current_possible_char[current_string_length];
				strcpy(result[p] + 1, result[j]);
				p += 1;
			}
		}
		current_string_length -= 1;
		for (j = 0; j < *returnSize; j++)
		{
			result[j] = (char*)realloc(result[j], (strlen(result[j]) + 1) * sizeof(char));
			strrev(result[j]);
			result[j][*returnSize + 1] = current_possible_char[current_string_length];
			result[j][*returnSize + 2] = '\0';
			strrev(result[j]);
		}
		*returnSize = next_size;
	}
	return result;
}

int main()
{
	char digits[] = "23";
	int returnSize;
	char **result;
	result = letterCombinations(digits, &returnSize);
	return 0;
}
