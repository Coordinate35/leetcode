#include <stdio.h>
#include <stdlib.h>

void sortColors(int* nums, int numsSize) {
    int red_pointer = -1, blue_pointer = numsSize;
    int i;
    int temp;
    for (i = red_pointer + 1; i < blue_pointer; i++) {
        if (0 == nums[i]) {
            temp = nums[i];
            nums[i] = nums[red_pointer + 1];
            nums[red_pointer + 1] = temp;
            red_pointer += 1;
            while (0 == nums[red_pointer + 1]) {
                red_pointer += 1;
                i += 1;
            }
        }
        if (2 == nums[i]) {
            temp = nums[blue_pointer - 1];
            nums[blue_pointer - 1] = nums[i];
            nums[i] = temp;
            blue_pointer -= 1;
            while (2 == nums[blue_pointer - 1]) {
                blue_pointer -= 1;
            }
            i -= 1;
        }
    }
}

int main() {
    int nums[] = {1, 2, 0};
    int numsSize = 3;
    sortColors(nums, numsSize);
    return 0;
}