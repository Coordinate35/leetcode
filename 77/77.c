#include <stdlib.h>
#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** combine(int n, int k, int** columnSizes, int* returnSize) {
    int **result;
    int col = 0;
    int i;
    *returnSize = 0;
    result = (int**)malloc((*returnSize + 3) * sizeof(int*));
    result[0] = (int*)malloc((k + 3) * sizeof(int));
    result[0][0] = 1;
    while (col >= 0) {
        while ((col >= 0) && (result[*returnSize][col] > n - k + 1 + col)) {
            col -= 1;
            if (col >=0) {
                result[*returnSize][col] += 1;
            }
        }
        if (col < 0) {
            columnSizes[0] = (int*)malloc((*returnSize + 3) * sizeof(int));
            for (i = 0; i < *returnSize; i++) {
                (*columnSizes)[i] = k;
            }
            return result;
        }
        while (col + 1 < k) {
            result[*returnSize][col + 1] = result[*returnSize][col] + 1;
            col += 1;
        }
        while (result[*returnSize][col] <= n) {
            *returnSize += 1;
            result = realloc(result, (*returnSize + 3) * sizeof(int*));
            result[*returnSize] = (int*)malloc((k + 3) * sizeof(int));
            for (i = 0; i < k; i++) {
                result[*returnSize][i] = result[*returnSize - 1][i];
            }
            result[*returnSize][col] += 1;
        }
    }
    return result;
}

int main() {
    int n = 6;
    int k = 3;
    int **result;
    int *columnSizes;
    int returnSize;
    int i, j;
    result = combine(n, k, &columnSizes, &returnSize);
    for (i = 0; i < returnSize; i++) {
        for (j = 0; j < columnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}