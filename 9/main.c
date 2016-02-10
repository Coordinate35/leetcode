#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int get_length(int x)
{
    int i = 0;
    while (0 != x / 10)
    {
        i += 1;
        x /= 10;
    }
    return i + 1;
}

int ten_pow(int length)
{
    int result = 1;
    while (length > 0)
    {
        result *= 10;
        length -= 1;
    }
    return result;
}

int get_nth_number(int num, int n)
{
    int selector, result;
    selector = ten_pow(n - 1);
    result = (num / selector) % 10;
    return result;
}

bool isPalindrome(int x)
{
    int length, i, loop_edge, front, back, back_index;
    if (x < 0)
    {
        return false;
    }
    length = get_length(x);
    loop_edge = length / 2;
    for (i = 1; i <= loop_edge; i++)
    {
        back = get_nth_number(x, i);
        back_index = length + 1 - i;
        front = get_nth_number(x, back_index);
        if (back != front)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int x, result;
    x = -214748;
    result = isPalindrome(x);
    printf("%d\n", result);
    return 0;
}
