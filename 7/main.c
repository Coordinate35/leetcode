#include <stdio.h>
#include <stdlib.h>

int get_length(int x)
{
    int length = -1;
    while (0 != x)
    {
        x /= 10;
        length += 1;
    }
    return length + 1;
}

int is_positive(int x)
{
    if (0 > x)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int get_ten_length(int length)
{
    int result = 1, i;
    for (i = 0; i < length; i++)
    {
        result *= 10;
    }
    return result;
}

int do_reverse(int x, int length)
{
    int result = 0;
    int last, rest, zero_number;
    last = x % 10;
    rest = x / 10;
    zero_number = get_ten_length(length - 1);
    if ((0 == last) && (0 == rest))
    {
        return result;
    }
    else
    {
        return last * zero_number + do_reverse(rest, length - 1);
    }
}


int reverse(int x)
{
    int character, result, no_character, length, test_result;
    character = is_positive(x);
    no_character = x * character;
    length = get_length(no_character);
    result = do_reverse(no_character, length);
    test_result = do_reverse(result, length);
    if (no_character == test_result)
    {
     int get_length(int x)
{
    int length = -1;
    while (0 != x)
    {
        x /= 10;
        length += 1;
    }
    return length + 1;
}

int is_positive(int x)
{
    if (0 > x)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int get_ten_length(int length)
{
    int result = 1, i;
    for (i = 0; i < length; i++)
    {
        result *= 10;
    }
    return result;
}

int do_reverse(int x, int length)
{
    int result = 0;
    int last, rest, zero_number;
    last = x % 10;
    rest = x / 10;
    zero_number = get_ten_length(length - 1);
    if ((0 == last) && (0 == rest))
    {
        return result;
    }
    else
    {
        return last * zero_number + do_reverse(rest, length - 1);
    }
}


int reverse(int x)
{
    int character, result, no_character, length, test_result;
    character = is_positive(x);
    no_character = x * character;
    length = get_length(no_character);
    result = do_reverse(no_character, length);
    test_result = do_reverse(result, length);
    if (x == test_result)
    {
        result *= character;
    }
    else
    {
        result = 0;
    }
    return result;
}   result *= character;
    }
    else
    {
        result = 0;
    }
    return result;
}

int main()
{
    int x, y;
    x = -123;
    y = reverse(x);
    printf("%d", y);
    return 0;
}
