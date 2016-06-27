/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

 #include <stdio.h>
 #include <stdbool.h>
 #include <stdlib.h>

void quicksort(int*a, int l, int r) {
    int privot = a[l];
    int i, j, temp;
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
            while (nums[i + 1] == nums[i]) {
                i += 1;
            }
        }
    }
    return result;
}

int** permuteUnique(int* nums, int numsSize, int* returnSize) {
    bool *available;
    int** result;
    int i;
    available = (bool*)malloc(numsSize * sizeof(bool));
    for (i = 0; i < numsSize; i++) {
        available[i] = true;
    }
    *returnSize = 0;
    quicksort(nums, 0, numsSize - 1);
    result = (int**)malloc(sizeof(int*));
    result[0] = (int*)malloc(numsSize * sizeof(int));
    result = do_permute(nums, numsSize, returnSize, 0, available, result);
    return result;
}

int main() {
    int nums[] = {1, 1, 3};
    int numsSize = 3;
    int returnSize;
    int **result;
    result = permuteUnique(nums, numsSize, &returnSize);
    return 0;
}