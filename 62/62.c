int uniquePaths(int m, int n) {
    int *window;
    int i, j;
    if ((1 == m) || (1 == n)) {
        return 1;
    }
    window = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        window[i] = 1;
    }
    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            window[j] += window[j - 1];
        }
    }
    return window[n - 1];
}