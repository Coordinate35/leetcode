#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Time limit exceeded
// int jump(int* nums, int numsSize) {
//     int i, j;
//     int min_jump;
//     int *result;
//     result = (int*)malloc(numsSize * sizeof(int));
//     result[0] = 0;
//     for (i = 1; i < numsSize; i++) {
//         result[i] = INT_MAX;
//     }

//     for (i = 1; i < numsSize; i++) {
//         min_jump = INT_MAX;
//         for (j = 0; j < i; j++) {
//             if ((nums[j] >= i - j) && (result[j] < min_jump)) {
//                 min_jump = result[j];
//             }
//         }
//         if (min_jump < INT_MAX) {
//             result[i] = min_jump + 1;
//         }
//     }
//     return result[numsSize - 1];
// }

int jump(int* nums, int numsSize) {
    int last = 0;
    int current = 0;
    int result = 0;
    int i;
    for (i = 0; i < numsSize; i++) {
        if (i > last) {
            last = current;
            result += 1;
        }
        if (i + nums[i] > current) {
            current = i + nums[i];
        }
    }
    return result;
}

int main() {
    int nums[] = {2, 3, 1, 1, 4};
    int numsSize = 5;
    int result = jump(nums, numsSize);
    printf("%d\n", result);
    return 0;
}