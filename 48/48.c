void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int temp;
    int i, j;
    for (i = 0; i < matrixRowSize / 2; i++) {
        for (j = i; j < matrixRowSize - i - 1; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[matrixRowSize - j - 1][i];
            matrix[matrixRowSize - j - 1][i] = matrix[matrixRowSize - i - 1][matrixRowSize - j - 1];
            matrix[matrixRowSize - i - 1][matrixRowSize - j - 1] = matrix[j][matrixRowSize - i - 1];
            matrix[j][matrixRowSize - i - 1] = temp;
        }
    }   
}
