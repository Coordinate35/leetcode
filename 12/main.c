#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_roman(char* roman, char* roman_num)
{
    int add_length = strlen(roman_num);
    int current_length = strlen(roman);
    roman = (char*)realloc(roman, add_length * sizeof(char));
    strcat(roman, roman_num);
    return roman;
}

char* intToRoman(int num)
{
    int number[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* roman_num[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i, j;
    int count;
    char* roman;
    roman = (char*)malloc(sizeof(char));
    *roman = '\0';
    for (i = 0; num > 0; i++)
    {
        count = num / number[i];
        num %= number[i];
        for (j = 1; j <= count; j++)
        {
            add_roman(roman, roman_num[i]);
        }
    }
    return roman;
}

int main()
{
    char* result;
    int num;
    num = 12;
    result = intToRoman(num);
    puts(result);
    return 0;
}
