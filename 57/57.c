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

int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
    struct Interval *result;
    int from = -1;
    int to;
    int i;
    int origin;
    *returnSize = 0;
    result = (struct Interval*)malloc((intervalsSize + 1) * sizeof(struct Interval));
    if (0 == intervalsSize) {
        result[0] = newInterval;
        *returnSize += 1;
        return result;
    }
    while ((newInterval.start >= intervals[from + 1].start) && (from < intervalsSize - 1)) {
        from += 1;
    }
    for (i = 0; i < from; i++) {
        result[*returnSize] = intervals[i];
        *returnSize += 1;
    }
    if (-1 == from) {
        result[*returnSize].start = newInterval.start;
        to = from;
    } else if (newInterval.start > intervals[from].end) {
        result[*returnSize] = intervals[from];
        *returnSize += 1;
        result[*returnSize].start = newInterval.start;
        to = from;
    } else {
        result[*returnSize].start  = intervals[from].start;
        to = from;
    }
    origin = to;
    while ((newInterval.end >= intervals[to + 1].start) && (to < intervalsSize - 1)) {
        to += 1;
    }
    if (-1 == to) {
        result[*returnSize].end = newInterval.end;
        *returnSize += 1;
    } else {
        result[*returnSize].end = max(newInterval.end, intervals[to].end);
        *returnSize += 1;
    }
    for (i = to + 1; i < intervalsSize; i++) {
        result[*returnSize] = intervals[i];
        *returnSize += 1;
    }
    return result;
}