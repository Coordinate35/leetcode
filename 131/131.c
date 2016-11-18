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

void dfs(char *s, char ***result, int** columnSize, int *returnSize, int* cut_point, int cut_number, int start) {
    int length = strlen(s);
    int i, j;
    int end = length - 1;
    if (start == length) {
        *returnSize += 1;
        *columnSize = realloc(*columnSize, (*returnSize) * sizeof(int));
        result = realloc(result, (*returnSize) * sizeof(char**));
        result[*returnSize - 1] = (char**)malloc(cut_number * sizeof(char*));
        for (i = 0; i <= cut_number; i++) {
            if (0 == i) {
                result[*returnSize - 1][i] = (char*)malloc((cut_point[i] + 1) * sizeof(char));
                for (j = 0; j < cut_point[i]; j++) {
                    result[*returnSize - 1][i][j] = s[j];
                }
            } else {
                result[*returnSize - 1][i] = (char*)malloc((cut_point[i] - cut_point[i - 1] + 1) * sizeof(char));
                for (j = 0; j < cut_point[i - 1] - cut_point[i]; j++) {
                    result[*returnSize - 1][i][j] = s[cut_point[i - 1] + j + 1];
                }
            }
            s[j] = '\0';
        }
        (*columnSize)[*returnSize - 1] = cut_number + 1;
    }

    while (end >= start) {
        if (is_palindrome(s, start, end)) {
            cut_point[cut_number] = end + 1;
            dfs(s, result, columnSize, returnSize, cut_point, cut_number + 1, end + 1);
        }
        end -= 1;
    }
}

char*** partition(char* s, int** columnSizes, int* returnSize) {
    char ***result;
    int *cut_point;
    cut_point = (int*)malloc(*returnSize * sizeof(int));
    result = (char***)malloc(0);
    *columnSizes = (int*)malloc(0);
    *returnSize = 0;
    dfs(s, result, columnSizes, returnSize, cut_point, 0, 0);
    return result;
}

int main() {
    char s[] = "aab";
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