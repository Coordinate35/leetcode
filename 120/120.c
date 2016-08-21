int miner(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    int min = INT_MAX;
    int i, j;
    for (i = 1; i < triangleRowSize; i++) {
        for (j = 0; j < triangleColSizes[i]; j++) {
            if (0 == j) {
                triangle[i][j] += triangle[i - 1][j];               
            } else if (triangleColSizes[i] - 1 == j) {
                triangle[i][j] += triangle[i - 1][j - 1];
            } else {
                triangle[i][j] += miner(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
    }      
    for (i = 0; i < triangleColSizes[triangleRowSize - 1]; i++) {
        if (triangle[triangleRowSize - 1][i] < min) {
            min = triangle[triangleRowSize - 1][i];
        }
    }
    return min;
}