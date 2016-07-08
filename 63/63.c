int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int *window;
    int i, j;
    window = (int*)malloc(obstacleGridColSize * sizeof(int));
    for (i = 0; i < obstacleGridRowSize; i++) {
        for (j = 0; j < obstacleGridColSize; j++) {
            if (0 == i) {
                if (0 == j) {
                    if (1 == obstacleGrid[i][j]) {
                        window[j] = 0;
                    } else {
                        window[j] = 1;
                    }
                } else {
                    if (1 == obstacleGrid[i][j]) {
                        window[j] = 0;
                    } else {
                        window[j] = window[j - 1];
                    }
                }
            } else {
                if (0 == j) {
                    if (1 == obstacleGrid[i][j]) {
                        window[j] = 0;
                    }
                } else {
                    if (1 == obstacleGrid[i][j]) {
                        window[j] = 0;
                    } else {
                        window[j] += window[j - 1];
                    }
                }
            }
        }
    }
    return window[obstacleGridColSize - 1];
}