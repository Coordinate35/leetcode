#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* convert(char* s, int numRows) {
    int length, i, step, position, p;
    char* zigzag;
    length = strlen(s);
    p = 0;
    zigzag = (char*)malloc(sizeof(char) * length);
	for (i = 1; i <= numRows; i++)
    {
        if ((i = 1) || (i = numRows))
        {
            step = 2 * (numRows - 1);
        }
        else
        {
            step = numRows;
        }
        position = i;
        while (position <= length)
        {
            zigzag[p] = s[position];
            p += 1;
            position += step;
        }
    }
    return zigzag;
}

int main()
{
	char text[20];
	char* result;
	int numRows;
	scanf(&numRows);
	gets(text);
	result = convert(text, numRows);
	puts(result);
	system('pause');
	return 0;
}
