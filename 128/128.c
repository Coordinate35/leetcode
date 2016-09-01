#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// int longestConsecutive(int* nums, int numsSize) {
//     long long i;
//     long long max = INT_MIN, min = INT_MAX;
//     long long min_to_zero;
//     long long container;
//     bool *is_used;
//     int max_length = 0;
//     int current_length = 0;
//     for (i = 0; i < numsSize; i++) {
//         if (nums[i] > max) {
//             max = nums[i];
//         }
//         if (nums[i] < min) {
//             min = nums[i];
//         }
//     }   
//     min_to_zero = 0 - min < 0 ? 0 : 0 - min;
//     container = max + 1 + min_to_zero;
//     is_used = (bool*)malloc(container * sizeof(bool));
//     for (i = 0; i < container; i++) {
//         is_used[i] = false; 
//     }
//     for (i = 0; i < numsSize; i++) {
//         is_used[nums[i] + min_to_zero] = true;
//     }
//     i = 0;
//     while (i < container) {
//         current_length = 0;
//         while ((i < container) && (false == is_used[i])) {
//             i += 1;
//         }
//         if (i >= container) {
//             return max_length;
//         }
//         while ((i < container) && (true == is_used[i])) {
//             i += 1;
//             current_length += 1;
//         }
//         if (current_length > max_length) {
//             max_length = current_length;
//         }
//     }
//     return max_length;
// }

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

int longestConsecutive(int* nums, int numsSize) {
    int i;
    int current_length = 0;
    int length = 0;
    if (0 == numsSize) {
        return 1;
    }
    quicksort(nums, 0, numsSize - 1);
    i = 0;
    while (i < numsSize) {
        current_length = 1;
        while ((i + 1 < numsSize) && (1 >= nums[i + 1] - nums[i])) {
            if (1 == nums[i + 1] - nums[i]) {
                current_length += 1;
            }
            i += 1;
        }
        if (current_length > length) {
            length = current_length;
        }
        i += 1;
    }
    return length;
}

int main() {
    int nums[] = {2147483646,-2147483647,0,2,2147483644,-2147483645,2147483645};
    int numsSize = 7;
    int max_length = longestConsecutive(nums, numsSize);
    printf("%d", max_length);
    return 0;
}