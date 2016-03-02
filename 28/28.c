#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pretreat(char* str, int* array)
{
	int i, j, str_length;
	str_length = strlen(str);
	array[0] = -1;
	j = -1;
	for (i = 1; i < str_length; i++)
	{
		while ((j >= 0) && (str[i] != str[j + 1]))
		{
			j = array[j];
		}
		if (str[j + 1] == str[i])
		{
			j += 1;
		}
		array[i] = j;
	}
}

/**
 * need function pretreat
 */
int kmp(char* haystack, char* needle)
{
	int haystack_length, needle_length, i, j;
	int *pretreatment;
	haystack_length = strlen(haystack);
	needle_length = strlen(needle);
	if (0 == needle_length)
	{
		return 0;
	}
	if (needle_length > haystack_length)
	{
		return -1;
	}
	pretreatment = (int*)malloc(needle_length * sizeof(int));
	pretreat(needle, pretreatment);
	j = -1;
	for (i = 0; i < haystack_length; i++)
	{
		while ((j >= 0) && (haystack[i] != needle[j + 1]))
		{
			j = pretreatment[j];
		}
		if (haystack[i] == needle[j + 1])
		{
			j += 1;
		}
		if (needle_length == j + 1)
		{
			return i - needle_length + 1;
		}
	}
	return -1;
}

int strStr(char* haystack, char* needle) 
{
	int position;
	position = kmp(haystack, needle);
	return position;
}

int main()
{
	char haystack[] = "mississippi";
	char needle[] = "si";
	int position;
	position = strStr(haystack, needle);
	printf("%d\n", position);
	return 0;
}