int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int i, j;
    if ((0 == gridRowSize) || (0 == gridColSize)) {
        return 0;
    }
    for (i = 0; i < gridRowSize; i++) {
        for (j = 0; j < gridColSize; j++) {
            if (0 == i) {
                if (0 != j) {
                    grid[i][j] += grid[i][j - 1];
                }
            } else {
                if (0 == j) {
                    grid[i][j] += grid[i - 1][j];
                } else {
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }
    }
    return grid[gridRowSize - 1][gridColSize - 1];
}