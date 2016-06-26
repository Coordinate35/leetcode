/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int** do_permute(int* nums, int numsSize, int* returnSize, int index, bool* available, int** result) {
    int i;
    if (numsSize == index) {
        *returnSize += 1;
        result = realloc(result, (*returnSize + 1) * sizeof(int*));
        result[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        for (i = 0; i < numsSize; i++) {
            result[*returnSize][i] = result[*returnSize - 1][i];
        }
        return result;
    }
    for (i = 0; i < numsSize; i++) {
        if (true == available[i]) {
            available[i] = false;
            result[*returnSize][index] = nums[i];
            result = do_permute(nums, numsSize, returnSize, index + 1, available, result);
            available[i] = true;
        }
    }
    return result;
}

int** permute(int* nums, int numsSize, int* returnSize) {
    bool *available;
    int** result;
    int i;
    available = (bool*)malloc(numsSize * sizeof(bool));
    for (i = 0; i < numsSize; i++) {
        available[i] = true;
    }
    *returnSize = 0;
    result = (int**)malloc(sizeof(int*));
    result[0] = (int*)malloc(numsSize * sizeof(int));
    result = do_permute(nums, numsSize, returnSize, 0, available, result);
    return result;
}