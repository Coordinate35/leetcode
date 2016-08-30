int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int rob(int* nums, int numsSize) {
    int i;
    int *f;
    if (0 == numsSize) {
        return 0;
    }
    f = (int*)malloc((numsSize + 1) * sizeof(int));
    f[0] = 0;
    f[1] = nums[0];
    for (i = 2; i <= numsSize; i++) {
        f[i] = max(f[i - 1], f[i - 2] + nums[i - 1]);
    }
    return f[numsSize];
}