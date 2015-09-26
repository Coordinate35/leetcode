# include<stdio.h>
# include<string.h>
# include<stdlib.h>

void expand(char *s, int *left, int *right, int length)
{
	while ((s[*left] == s[*right]) && (*left >= 0) && (*right < length))
	{
		(*left)--;
		(*right)++;
		if ((*left < 0) || (*right == length))
		{
			break;
		}
	}
}

void judge(int *max_start, int *max_length, int left, int right)
{
	int length;
	length = right - left - 1;
	if (length > *max_length)
	{
		*max_start = left + 1;
		*max_length = length;
	}
}

char* longestPalindrome(char* s)
{
	int left, right, length, i, max_length, max_start;
	char *result;
	length = strlen(s);
	max_length = 0;
	max_start = -1;
	for (i = 0; i < length - (max_length / 2); i++)
	{
		left = i;
		right = i;
		while (s[right] == s[left])
		{
			right++;
		}
		right--;
		expand(s, &left, &right, length);
		judge(&max_start, &max_length, left, right);
	}
	result = (char*)calloc(max_length + 1, sizeof(char));
	for (i = 0; i < max_length; i++)
	{
		result[i] = s[max_start + i];
	}
	result[max_length + 1] = '\0';
	return result;
}

int main()
{
	char s[20];
	char *palindrome;
	gets_s(s, 20 * sizeof(char));
	palindrome = longestPalindrome(s);
	puts(palindrome);
	getchar();
	return 0;
}