#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(char* s, char* p)
{
    if ('\0' == p[0])
    {
        if ('\0' == s[0])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if ('*' != p[1])
    {
        if ((p[0] == s[0]) || (('.' == p[0]) && ('\0' != s[0])))
        {
            return isMatch(s + 1, p + 1);
        }
        else
        {
            return false;
        }
    }
    else
    {
        while ((p[0] == s[0]) || (('.' == p[0]) && ('\0' != s[0])))
        {
            if (isMatch(s, p + 2))
            {
                return true;
            }
            s += 1;
        }
        return isMatch(s, p + 2);
    }
}

int main()
{
    char s[] = "aab";
    char p[] = "c*a*b";
    int result;
    result = isMatch(s, p);
    printf("%d\n", result);
    return 0;
}
