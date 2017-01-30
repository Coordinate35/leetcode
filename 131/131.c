#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

bool is_palindrome(char *s, int start, int end) {
    while ((end > start) && (s[start] == s[end])) {
        end -= 1;
        start += 1;
    }
    return start >= end;
}

void dfs(char* s, char**** result, int** columnSize, int* returnSize, int* cut_point, int cut_number, int start) {
    int length = strlen(s);
    int i = 0, j = 0;
    int end = length - 1;
    int sub_string_length = 0;
    if (start == length) {
        *returnSize += 1;
        *columnSize = realloc(*columnSize, (*returnSize + 1) * sizeof(int));
        *result = realloc(*result, (*returnSize + 1) * sizeof(char**));
        (*result)[*returnSize - 1] = (char**)malloc((cut_number + 1) * sizeof(char*));
        for (i = 0; i < cut_number; i++) {
            sub_string_length = cut_point[i + 1] - cut_point[i];
            (*result)[*returnSize - 1][i] = (char*)malloc((sub_string_length + 1) * sizeof(char));
            strncpy((*result)[*returnSize - 1][i], s + cut_point[i] + 1, sub_string_length);
            (*result)[*returnSize - 1][i][sub_string_length] = '\0';
            (*columnSize)[*returnSize - 1] = cut_number;
        }
    }

    while (end >= start) {
        if (is_palindrome(s, start, end)) {
            cut_point[cut_number + 1] = end;
            dfs(s, result, columnSize, returnSize, cut_point, cut_number + 1, end + 1);
        }
        end -= 1;
    }
}

char*** partition(char* s, int** columnSizes, int* returnSize) {
    char ***result;
    int *cut_point;
    int s_length = strlen(s);
    cut_point = (int*)malloc(s_length * sizeof(int));
    cut_point[0] = -1;
    result = (char***)malloc(sizeof(char**));
    result[0] = (char**)malloc(sizeof(char*));
    *columnSizes = (int*)malloc(sizeof(int));
    (*columnSizes)[0] = 0;
    *returnSize = 0;
    if (NULL == s) {
        return NULL;
    }
    dfs(s, &result, columnSizes, returnSize, cut_point, 0, 0);
    return result;
}

int main() {
    // char s[] = "fff";
    // char s[] = "aab";
    // char s[] = "seeslaveidemonstrateyetartsnomedievalsees";
    // char s[] = "aaaaa";
    char s[] = "cbbbcc";
    int *columnSizes;
    int returnSize;
    int i, j;
    char ***result;
    result = partition(s, &columnSizes, &returnSize);
    for (i = 0; i < returnSize; i++) {
        for (j = 0; j < columnSizes[i]; j++) {
            puts(result[i][j]);
        }
        printf("\n");
    }
    return 0;
}