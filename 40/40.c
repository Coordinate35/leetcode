/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 #include <stdio.h>
 #include <stdlib.h>

void quicksort(int *a, int l, int r) {
    int i, j, temp;
    int privot = a[l];
    j = l;
    if (l < r) {
        for (i = l; i <= r; i++) {
            if (a[i] < privot) {
                temp = a[j];
                a[j] = a[i];
                a[i] = a[j + 1];
                a[j + 1] = temp;
                j++;
            }
        }
        quicksort(a, l, j - 1);
        quicksort(a, j + 1, r);
    }
}

int** dfs(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize, int** result, int last_index) {
    int i;
    if (0 > target) {
        return result;
    }

    if (0 == target) {
        *returnSize += 1;
        result = realloc(result, (*returnSize + 1) * sizeof(int*));
        result[*returnSize] = (int*)malloc(((*columnSizes)[*returnSize - 1]) * sizeof(int));
        for (i = 0; i < (*columnSizes)[*returnSize - 1]; i++) {
            result[*returnSize][i] = result[*returnSize - 1][i];
        }
        *columnSizes = realloc(*columnSizes, (*returnSize + 1) * sizeof(int));
        (*columnSizes)[*returnSize] = (*columnSizes)[*returnSize - 1];
        return result;
    }

    for (i = last_index + 1; i < candidatesSize; i++) {
        if (candidates[i] <= target) {
            result[*returnSize][(*columnSizes)[*returnSize]] = candidates[i];
            (*columnSizes)[*returnSize] += 1;
            result[*returnSize] = realloc(result[*returnSize], ((*columnSizes)[*returnSize] + 1) * sizeof(int));
            result = dfs(candidates, candidatesSize, target - candidates[i], columnSizes, returnSize, result, i);
            (*columnSizes)[*returnSize] -= 1;
        }
        while (candidates[i] == candidates[i + 1]) {
            i += 1;
        }
    }
    return result;
}
 
int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    int **result;
    columnSizes[0] = (int*)malloc(sizeof(int));
    (*columnSizes)[0] = 0;
    *returnSize = 0;
    result = (int**)malloc(sizeof(int*));
    result[0] = (int*)malloc(sizeof(int));
    quicksort(candidates, 0, candidatesSize - 1);
    result = dfs(candidates, candidatesSize, target, columnSizes, returnSize, result, -1);
    if ((0 == *returnSize) || (0 == candidatesSize)) {
        return NULL;
    }
    return result;
}

int main() {
    int candidates[] = {10, 1, 2, 7, 6, 1, 5};
    int candidatesSize = 7;
    int target = 8;
    int *columnSizes;
    int returnSize;
    int **result;
    int i, j;
    result = combinationSum2(candidates, candidatesSize, target, &columnSizes, &returnSize);
    for (i = 0; i < returnSize; i++) {
        for (j = 0; j < columnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}