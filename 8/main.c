#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int is_positive(char* str, int start)
{
    int is_pos;
    if ('+' == str[start])
    {
        is_pos = 1;
    }
    else if ('-' == str[start])
    {
        is_pos = -1;
    }
    else
    {
        is_pos = 1;
    }
    return is_pos;
}

int char2num(char character)
{
    int char_num_step = 48;
    return character - char_num_step;
}

int is_digit(char character)
{
    if ((48 <= character) && (57 >= character))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int get_start(char* str)
{
    int length, i;
    length = strlen(str);
    i = 0;
    while (' ' == str[i])
    {
        i += 1;
    }
    return i;
}

int myAtoi(char* str)
{
    int result = 0, i, length, last, buffer, start, is_pos;
    length = strlen(str);
    start = get_start(str);
    if (start >= length)
    {
        return 0;
    }
    is_pos = is_positive(str, start);
    if (('-' == str[start]) || ('+' == str[start]))
    {
        start += 1;
    }
    else if ((10 == length) && (str[start] >= 3))
    {
        return INT_MAX;
    }
    i = start;
    while ((i < length) && (is_digit(str[i])))
    {
        last = char2num(str[i]);
        buffer = result * 10 + is_pos * last;
        //printf("%d\n%d\n%d\n%d\n", i, last, buffer, result);
        if ((-1 == is_pos) && (buffer / 10 - (is_pos * last / 10) != result))
        {
            return INT_MIN;
        }
        else if ((1 == is_pos) && (buffer / 10 - (is_pos * last / 10) != result))
        {
            return INT_MAX;
        }
        else
        {
            result = buffer;
        }
        i += 1;
    }
    return result;
}

int main()
{
    char str[] = "";
    int number;
    number = myAtoi(str);
    printf("%d\n", number);
    return 0;
}
