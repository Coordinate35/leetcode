int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int minCut(char* s) {
    int length = strlen(s);
    int i, j;
    int *f;
    f = (int*)malloc(length * sizeof(int));
    for (i = 0; i < length; i++) {
        f[i] = INT_MAX;
    }   
    f[0] = 0;
    for (i = 1; i < length; i++) {
        j = 0;
        while ((0 <= i - j) && (length > i + j) && (s[i - j] == s[i + j])) {
            if (0 == i - j) {
                f[i + j] = 0;
            } else {
                f[i + j] = min(f[i + j], f[i - j - 1] + 1);
            }
            j += 1;
        }
        j = 0;
        while ((0 < i - j) && (length > i + j) && (s[i - j - 1] == s[i + j])) {
            if (1 == i - j) {
                f[i + j] = 0;
            } else {
                f[i + j] = min(f[i + j], f[i - j - 2] + 1);
            }
            j += 1;
        }
    } 
    return f[length - 1];
}