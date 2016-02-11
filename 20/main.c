#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s)
{
    int length, stack_length, i, p;
    char* stack;
    length = strlen(s);
    stack_length = length / 2;
    stack = (char*)malloc(stack_length * sizeof(char));
    p = 0;
    for (i = 0; i < length; i++)
    {
        //printf("%c\n%c\n%d\n\n", s[i], stack[p - 1], i);
        if (('(' == s[i])
             || ('[' == s[i])
             || ('{' == s[i]))
        {
            stack[p] = s[i];
            p += 1;
        }
        else if (((s[i] == ')') && (stack[p - 1] == '('))
                 || ((s[i] == ']') && (stack[p - 1] == '['))
                 || ((s[i]) == '}') && (stack[p - 1] == '{'))
        {
            p -= 1;
        }
        else
        {
            return false;
        }
    }
    //printf("%d\n%d\n\n", p, stack);
    if (p == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char s[] = "[()]()";
    int result;
    result = isValid(s);
    printf("%d", result);
    return 0;
}
