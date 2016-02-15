#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
    int first_length, j, i;
    char current;
    char* result;
    if (0 == strsSize)
    {
        return "";
    }
    first_length = strlen(strs[0]);
    for (i = 0; i < first_length; i++)
    {
        current = strs[0][i];
        for (j = 1; j < strsSize; j++)
        {
            if (current != strs[j][i])
            {
                result = (char*)malloc((i + 1) * sizeof(char));
                strncpy(result, strs[0], i);
                result[i] = '\0';
                return result;
            }
        }
    }
    return strs[0];
}

int main()
{
    char* strs[] = {"cba", ""};
    char* result;
    int strsSize;
    strsSize = 2;
    result = longestCommonPrefix(strs, strsSize);
    puts(result);
    return 0;
}
