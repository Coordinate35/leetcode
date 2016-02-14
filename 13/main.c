#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int basic_roman_to_int(char roman)
{
    switch(roman)
    {
        case 'M': return 1000;
        case 'D': return 500;
        case 'C': return 100;
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;
    }
}

int romanToInt(char* s)
{
    int i;
    int number = 0, num_i, num_next;
    int length = strlen(s);
    int loop_limit;
    loop_limit = length - 1;
    num_next = basic_roman_to_int(s[0]);
    for (i = 0; i < loop_limit; i++)
    {
        num_i = num_next;
        num_next = basic_roman_to_int(s[i + 1]);
        if (num_i < num_next)
        {
            number -= num_i;
        }
        else
        {
            number += num_i;
        }
    }
    number += num_next;
    return number;
}

int main()
{
    char s[] = "X";
    int number;
    number = romanToInt(s);
    printf("%d", number);
    return 0;
}
