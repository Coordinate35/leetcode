/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

 #include<stdio.h>
 #include<stdlib.h>

void find_range(int* nums, int numsSize, int left, int right, int* result, int target) {
    int middle = (left + right) / 2;
    if (left > right) {
        return;
    }
    if (nums[middle] == target) {
        //Deal with left
        if (0 == middle) {
            result[0] = 0;
        } else if (target != nums[middle - 1]) {
            result[0] = middle;
        }
        //Deal with right
        if (numsSize - 1 == middle) {
            result[1] = numsSize - 1;
        } else if (target != nums[middle + 1]) {
            result[1] = middle;
        }
        find_range(nums, numsSize, left, middle - 1, result, target);
        find_range(nums, numsSize, middle + 1, right, result, target);
    } else if (target < nums[middle]) {
        find_range(nums, numsSize, left, middle - 1, result, target);
    } else {
        find_range(nums, numsSize, middle + 1, right, result, target);
    }
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *result;
    int left = 0;
    int right = numsSize - 1;
    result = (int*)malloc((*returnSize) * sizeof(int));
    result[0] = -1;
    result[1] = -1;
    find_range(nums, numsSize, left, right, result, target);
    return result;   
}

int main() {
    int nums[] = {5, 7};
    int numsSize = 2;
    int target = 10;
    int returnSize;
    int i;
    int *result;
    result = searchRange(nums, numsSize, target, &returnSize);
    for (i = 0; i < returnSize; i++) {
        printf("%d\n", result[i]);
    }
    return 0;
}