#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* convert(char* s, int numRows) {
    int length, i, step, position, p, step_sum;
    char* zigzag;
    if (1 == numRows)
    {
        step_sum = 1;
    }
    else
    {
        step_sum = 2 * (numRows - 1);
    }
    length = strlen(s);
    p = 0;
    zigzag = (char*)malloc((sizeof(char) + 1) * length);
    if (0 == length)
    {
        return zigzag;
    }
    for (i = 0; i < numRows; i++)
    {
        position = i;
        if ((i == 0) || (i == numRows - 1))
        {
            step = step_sum;
        }
        else
        {
            step = (numRows - 1 - i) * 2;
        }
        while (position < length)
        {
            zigzag[p] = s[position];
            p += 1;
            position += step;
            if ((i == 0) || (i == numRows - 1))
            {
                step = step_sum;
            }
            else
            {
                step = step_sum - step;
            }
        }
    }
    zigzag[p] = '\0';
    return zigzag;
}

int main()
{
    char text[] = "glzamzp";
    char* result;
    int numRows;
    // scanf("%d", &numRows);
    // scanf("%s", text);
    numRows = 5;
    result = convert(text, numRows);
    puts(result);
    printf("%d", strlen(result));
    system("pause");
    return 0;
}
