#include<stdio.h>
#include<stdlib.h>

#define STRING_LENGTH 20

int get_length(char *s)
{
	int i;
	i = 0;
	while ('\0' != s[i])
	{
		i++;
	}
	return i;
}

int lengthOfLongestSubstring(char* s)
{
	int length, i, max, j, k;
	bool is_set[256];
	length = get_length(s);
	max = 0;
	for (i = 0; i < length; i++)
	{
		for (j = 0; j < 256; j++)
		{
			is_set[j] =	false;
		}
		k = i;

		while ((is_set[s[k]] != true) && (k < length))
		{
			is_set[s[k]] = true;
			k++;
		}

		if (k - i > max)
		{
			max = k - i;
		}
	}

	return max;
}

int main()
{
	char string[STRING_LENGTH];
	gets_s(string, STRING_LENGTH * sizeof(char));
	printf("%d", lengthOfLongestSubstring(string));
	return 0;
}