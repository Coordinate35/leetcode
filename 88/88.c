#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int m, int* nums2, int n) {
    int* nums_bak;
    int temp;
    int i, j, k;
    nums_bak = (int*)malloc(m * sizeof(int));
    for (i = 0; i < m; i++) {
        nums_bak[i] = nums1[i];
    }
    k = 0;
    i = 0;
    j = 0;
    while ((i < m) && (j < n)) {
        if (nums_bak[i] < nums2[j]) {
            nums1[k] = nums_bak[i];
            i += 1;
        } else {
            nums1[k] = nums2[j];
            j += 1;
        }
        k += 1;
    }
    if (i == m) {
        while (j < n) {
            nums1[k] = nums2[j];
            k += 1;
            j += 1;
        }
    } else {
        while (i < m) {
            nums1[k] = nums_bak[i];
            i += 1;
            k += 1;
        }
    }
    // free(nums_bak);   
}

int main() {
    int m = 5;
    int n = 3;
    int nums1[8] = {1, 3, 5, 7, 9};
    int nums2[3] = {2, 4, 6};
    int i;
    merge(nums1, m, nums2, n);
    for (i = 0; i < (m + n); i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");
    return 0;
}