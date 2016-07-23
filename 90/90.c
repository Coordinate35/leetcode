/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

void quicksort(int* nums, int l, int r) {
    int privot = nums[l];
    int i, j;
    int temp;
    j = l;
    if (l < r) {
        for (i = l; i <= r; i++) {
            if (nums[i] < privot) {
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = nums[j + 1];
                nums[j + 1] = temp;
                j += 1;
            }
        }
        quicksort(nums, l, j - 1);
        quicksort(nums, j + 1, r);
    } 
}

void reverse_array(int* nums, int numsSize) {
    int middle = numsSize / 2;
    int i;
    int temp;
    for (i = 0; i < middle; i++) {
        temp = nums[i];
        nums[i] = nums[numsSize - i - 1];
        nums[numsSize - i - 1] = temp;
    }
}

void reverse_array_pointer(int** result, int returnSize) {
    int middle = returnSize / 2;
    int i;
    int* temp;
    for (i = 0; i < middle; i++) {
        temp = result[i];
        result[i] = result[returnSize - i - 1];
        result[returnSize - i - 1] = temp; 
    }
}

int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int **result; 
    int last = 0;
    int i, j, k;
    int update_from;
    int last_size;
    int dup_number;
    quicksort(nums, 0, numsSize - 1);
    reverse_array(nums, numsSize);
    *returnSize = 0;
    result = (int**)malloc(sizeof(int*));
    *columnSizes = (int*)malloc(sizeof(int));
    if (0 == numsSize) {
        *returnSize = 1;
        (*columnSizes)[0] = 0;
        result[0] = NULL;
        return result;
    }

    dup_number = 0;
    i = 0;
    while ((dup_number + 1 < numsSize) && (nums[dup_number + 1] == nums[dup_number])) {
        dup_number += 1;
    }
    dup_number += 1;
    *returnSize += dup_number;
    *columnSizes = realloc(*columnSizes, (*returnSize) * sizeof(int));
    result = realloc(result, (*returnSize) * sizeof(int*));
    for (k = dup_number; k > 0; k--) {
        (*columnSizes)[*returnSize - k] = k;
        result[*returnSize - k] = (int*)malloc(k * sizeof(int));
        for (j = 0; j < k; j++) {
            result[*returnSize - k][j] = nums[i];
        }
    }
    for (i = dup_number; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            update_from = last_size; 
        } else {
            last = i;
            update_from = 0;
        }
        last_size = *returnSize;
        *returnSize += *returnSize - update_from;
        result = realloc(result, (*returnSize) * sizeof(int*));
        *columnSizes = realloc(*columnSizes, (*returnSize) * sizeof(int));
        for (j = last_size; j < *returnSize; j++) {
            (*columnSizes)[j] = (*columnSizes)[j - last_size + update_from] + 1;
            result[j] = (int*)malloc((*columnSizes)[j] * sizeof(int));
            for (k = 0; k < (*columnSizes)[j] - 1; k++) {
                result[j][k] = result[j - last_size + update_from][k];
            }
            result[j][(*columnSizes)[j] - 1] = nums[i];
        }
        if ((i == numsSize - 1) || (nums[i] != nums[i + 1])) {
            dup_number = i - last + 1;
            *returnSize += dup_number;
            *columnSizes = realloc(*columnSizes, (*returnSize) * sizeof(int*));
            result = realloc(result, (*returnSize) * sizeof(int*));
            for (k = dup_number; k > 0; k--) {
                (*columnSizes)[*returnSize - k] = k;
                result[*returnSize - k] = (int*)malloc(k * sizeof(int));
                for (j = 0; j < k; j++) {
                    result[*returnSize - k][j] = nums[i];
                }
            }
        }
    }
    *returnSize += 1;
    result = realloc(result, (*returnSize) * sizeof(int*));
    *columnSizes = realloc(*columnSizes, (*returnSize) * sizeof(int));
    result[*returnSize - 1] = NULL;
    (*columnSizes)[*returnSize - 1] = 0;

    reverse_array_pointer(result, *returnSize);
    reverse_array(*columnSizes, *returnSize);
    for (i = 0; i < *returnSize; i++) {
        reverse_array(result[i], (*columnSizes)[i]);
    }
    return result;
}

int main() {
    int nums[] = {1, 2, 3};
    int numsSize = 5;
    int returnSize;
    int *columnSizes;
    int** result;
    int i, j;
    result = subsetsWithDup(nums, numsSize, &columnSizes, &returnSize);
    for (i = 0; i < returnSize; i++) {
        for (j = 0; j < columnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}