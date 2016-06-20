/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 #include <stdio.h>
 #include <stdlib.h>

int** dfs(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize, int** result) {
    int i;
    if (0 > target) {
        return result;
    }

    if (0 == target) {
        *returnSize += 1;
        result = realloc(result, (*returnSize + 1) * sizeof(int*));
        result[*returnSize] = (int*)malloc(sizeof(int));
        columnSizes[*returnSize] = (int*)malloc(sizeof(int));
        *columnSizes[*returnSize] = 0;
        return result;
    }

    for (i = 0; i < candidatesSize; i++) {
        if (candidates[i] <= target) {
            result[*returnSize][*columnSizes[*returnSize]] = candidates[i];
            *columnSizes[*returnSize] += 1;
            result[*returnSize] = realloc(result[*returnSize], (*columnSizes[*returnSize] + 1) * sizeof(int));
            result = dfs(candidates, candidatesSize, target - candidates[i], columnSizes, returnSize, result);
            *columnSizes[*returnSize] -= 1;
        }
    }
    return result;
}
 
int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    int **result;
    columnSizes = (int**)malloc(sizeof(int*));
    columnSizes[0] = (int*)malloc(sizeof(int));
    *columnSizes[0] = 0;
    *returnSize = 0;
    result = (int**)malloc(sizeof(int*));
    result[0] = (int*)malloc(sizeof(int));
    result = dfs(candidates, candidatesSize, target, columnSizes, returnSize, result);
    if (0 == *returnSize) {
        return NULL;
    }
    return result;
}

int main() {
    int candidates[] = {2, 3, 6, 7};
    int candidatesSize = 4;
    int target = 7;
    int **columnSizes;
    int returnSize;
    int ** result;
    int i, j;
    result = combinationSum(candidates, candidatesSize, target, columnSizes, &returnSize);
    for (i = 0; i < returnSize; i++) {
        for (j = 0; j < *columnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}