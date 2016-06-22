int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int trap(int* height, int heightSize) {
    int i;
    int *left_max, *right_max;
    int min_height;
    int water = 0;
    left_max = (int*)malloc(heightSize * sizeof(int));
    right_max = (int*)malloc(heightSize * sizeof(int));
    left_max[0] = 0;
    right_max[heightSize - 1] = 0;
    for (i = 1; i < heightSize - 1; i++) {
        left_max[i] = max(left_max[i - 1], height[i - 1]);
        right_max[heightSize - i - 1] = max(right_max[heightSize - i], height[heightSize - i]);
    }
    for (i = 1; i < heightSize - 1; i++) {
        min_height = min(left_max[i], right_max[i]);
        if (height[i] < min_height) {
            water += min_height - height[i];
        }
    }
    return water;
}