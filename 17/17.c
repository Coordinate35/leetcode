#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

char** dfs(char* digits, int* returnSize, char** result, char* path)
{
	int length, i, str_length, path_length;
	char* str;

	length = strlen(digits);

	if (0 == length)
	{
		char* one_result;
		int result_length;

		result_length = strlen(path);
		*returnSize += 1;
		result = (char**)realloc(result, *returnSize * sizeof(char*));
		one_result = (char*)malloc((result_length + 1) * sizeof(char));
		strcpy(one_result, path);
		result[*returnSize - 1] = one_result;
		path[result_length - 1] = '\0';
		return result;
	}

	str = get_current_possible_char(digits[0]);
	str_length = strlen(str);
	path_length = strlen(path);
	digits += 1;
	for (i = 0; i < str_length; i++)
	{
		path[path_length] = str[i];
		path[path_length + 1] = '\0';
		result = dfs(digits, returnSize, result, path);
		path[path_length] = '\0';
	}
	digits -= 1;
	return result;
}

char** letterCombinations(char* digits, int* returnSize)
{
	char **result;
	char *path;
	int level, length;
	length = strlen(digits);
	result = (char**)malloc(0);
	if (0 == length)
	{
		return NULL;
	}
	level = 0;
	path = (char*)malloc((length + 1) * sizeof(char));
	path[0] = '\0';
	result = dfs(digits, returnSize, result, path);
}

int main()
{
	char digits[] = "";
	int returnSize, i;
	char **result;
	returnSize = 0;
	result = letterCombinations(digits, &returnSize);
	for (i = 0; i < returnSize; i++)
	{
		puts(result[i]);
		printf("\n");
	}
	return 0;
}
