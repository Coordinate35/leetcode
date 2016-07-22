/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    int *result;
    int i, j;
    int size = 1;
    int order;
    if (0 == n) {
        result = (int*)malloc(sizeof(int));
        result[0] = 0;
        *returnSize = 1;
        return result;
    }
    *returnSize = 1;
    for (i = 0; i < n; i++) {
        *returnSize *= 2;
    }
    result = (int*)malloc((*returnSize) * sizeof(int));
    result[0] = 0;
    result[1] = 1;
    for (i = 1; i < n; i++) {
        size *= 2;
        for (j = size - 1; j >= 0; j--) {
            order = size - j - 1;
            result[size + order] = size + result[j];
        }
    }
    return result;
}