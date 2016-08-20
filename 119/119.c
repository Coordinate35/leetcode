/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int **result;
    int i, j;
    rowIndex += 1;
    result = (int**)malloc(rowIndex * sizeof(int*));
    for (i = 0; i < rowIndex; i++) {
        result[i] = (int*)malloc((i + 1) * sizeof(int));
        result[i][0] = 1;
        result[i][i] = 1;
        for (j = 1; j < i; j++) {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }
    *returnSize = rowIndex;
    return result[rowIndex - 1];
}