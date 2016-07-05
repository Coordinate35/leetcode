/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>

struct Interval {
    int start;
    int end;
};

void quicksort(struct Interval *a, int l, int r) {
    int i, j;
    struct Interval temp;
    int privot = a[l].start;
    j = l;
    if (l < r) {
        for (i = l; i <= r; i++) {
            if (a[i].start < privot) {
                temp = a[j];
                a[j] = a[i];
                a[i] = a[j + 1];
                a[j + 1] = temp;
                j += 1;
            }
        }
        quicksort(a, l, j - 1);
        quicksort(a, j + 1, r);
    }
}

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    struct Interval *result;
    int i;
    if (0 == intervalsSize) {
        return NULL;
    }
    result = (struct Interval*)malloc(sizeof(struct Interval));
    quicksort(intervals, 0, intervalsSize - 1);
    *returnSize = 0;
    result[0] = intervals[0];
    for (i = 1; i < intervalsSize; i++) {
        if (result[*returnSize].end >= intervals[i].start) {
            if ((result[*returnSize].end < intervals[i].end)) {
                result[*returnSize].end = intervals[i].end;
            }
        } else {
            *returnSize += 1;
            result = realloc(result, (*returnSize + 1) * sizeof(struct Interval));
            result[*returnSize] = intervals[i];
        }
    }
    *returnSize += 1;
    return result;
}

int main() {
    struct Interval intervals[] = {{1, 4}, {0, 2}, {3, 5}};
    struct Interval *result;
    int returnSize;
    int intervalsSize = 3;
    result = merge(intervals, intervalsSize, &returnSize);
    return 0;
}