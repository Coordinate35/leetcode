#include <stdio.h>
#include <stdlib.h>

void quicksort(int *a, int l, int r) {
    int i, j, temp;
    int pivot = a[l];
    j = l;
    if (l < r) {
        for (i = l; i <= r; i++) {
            if (a[i] < pivot) {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
                j++;
            } 
        }
        quicksort(a, l, j - 1);
        quicksort(a, j + 1, r);
    }
}

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 1;
    int j, temp;
    int *first_minor;
    int chosen_to_change = numsSize - 1;
    first_minor = (int*)malloc(numsSize * sizeof(int)); 
    for (i = numsSize - 1; i > 0; i--) {
        for (j = i - 1; j >= 0; j--) {
            if (nums[j] < nums[i]) {
                first_minor[i] = j;
                break;
            }
        }
        if (-1 == j) {
            first_minor[i] = -1;
        }
    }
    for (i = numsSize - 1; i > 0; i--) {
        if (first_minor[i] > first_minor[chosen_to_change]) {
            chosen_to_change = i; 
        } else if ((first_minor[i] == first_minor[chosen_to_change]) 
                && (nums[i] < nums[chosen_to_change])) {
            chosen_to_change = i;
        }
    }
    if (-1 != first_minor[chosen_to_change]) { 
        temp = nums[chosen_to_change];
        nums[chosen_to_change] = nums[first_minor[chosen_to_change]];
        nums[first_minor[chosen_to_change]] = temp;
        quicksort(nums, first_minor[chosen_to_change] + 1, numsSize - 1);
    } else {
        quicksort(nums, 0, numsSize - 1);
    }
}

int main() {
    // int nums[] = {5, 4, 7, 5, 3, 2};
    // int nums[] = {4, 2, 0, 2, 3, 2, 0};
    // int nums[] = {2,3,1};
    // int nums[] = {1,1};
    int nums[] = {3, 2, 1};
    int numsSize = 3;
    nextPermutation(nums, numsSize);
    while (numsSize > 0) {
        printf("%d ", nums[numsSize - 1]);
        numsSize--;
    }
    return 0;
}