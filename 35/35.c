#include <stdio.h>
#include <stdlib.h> 

void find_insert_position(int* nums, int numsSize, int left, int right, int target, int* insert_position) {
    int middle = (left + right) / 2;
    if (left > right) {
        return;
    }
    if (target == nums[middle]) {
        *insert_position = middle;
    } else {
        if ((0 == middle) || (numsSize - 1 == middle)) {
            if (0 == middle) {
                if (nums[0] > target)  {
                    if (1 == numsSize) {
                        *insert_position = 0;
                    } else if (target < nums[1]) {
                        *insert_position = 0;
                    }
                }
            } 
            if (numsSize - 1 == middle) {
                if (target > nums[numsSize - 1]) {
                    *insert_position = numsSize;
                } else if ((target < nums[numsSize - 1]) && (target > nums[numsSize - 2])) {
                    *insert_position = numsSize - 1;
                }
            }
        } else {
            if ((target < nums[middle]) && (target > nums[middle - 1])) {
                *insert_position = middle;
            }
        }
        if (target > nums[middle]) {
            find_insert_position(nums, numsSize, middle + 1, right, target, insert_position);
        } else {
            find_insert_position(nums, numsSize, left, middle - 1, target, insert_position);  
        }
    }
}

int searchInsert(int* nums, int numsSize, int target) {
    int insert_position;
    find_insert_position(nums, numsSize, 0, numsSize - 1, target, &insert_position);
    return insert_position;
}

int main() {
    int nums[] = {1, 3};
    int numsSize = 2;
    int target = 2;
    int insert_position = searchInsert(nums, numsSize, target);
    printf("%d\n", insert_position);
    return 0;
}