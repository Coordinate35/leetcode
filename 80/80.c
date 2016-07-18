#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    int *result;
    int result_pointer = 0;
    int allow_appearance = 2;
    int appeared_number;
    int i;
    if (0 == numsSize) {
        return 0;
    }
    result = (int*)malloc(numsSize * sizeof(int));
    for (i = 0; i < numsSize; i++) {
        appeared_number = 1;
        result[result_pointer] = nums[i];
        result_pointer += 1;
        while ((nums[i + 1] == nums[i]) && (i + 1 < numsSize)) {
            i += 1;
            if (appeared_number < allow_appearance) {
                result[result_pointer] = nums[i];
                result_pointer += 1;
                appeared_number += 1;
            }
        }
    }
    for (i = 0; i < result_pointer; i++) {
        nums[i] = result[i];
    }
    free(result);
    return result_pointer;
}

// int removeDuplicates(int* nums, int numsSize) {
//     int i = 1, j = 1;
//     int appeared_number = 1;
//     if (0 == numsSize) {
//         return 0;
//     }
//     for (i = 1; i < numsSize; i++) {
//         if (nums[i] == nums[i - 1]) {
//             appeared_number += 1;
//             if (appeared_number <= 2) {
//                 nums[j] = nums[i];
//                 j += 1;
//             }
//         } else {
//             nums[j] = nums[i];
//             appeared_number = 1;
//             j += 1;
//         }
//     }
//     return j;
// }

int main() {
    int nums[] = {0,0,1,1,1,2,2,2,3,3,4};
    int numsSize = 11;
    int returnSize = removeDuplicates(nums, numsSize);
    return 0;
}