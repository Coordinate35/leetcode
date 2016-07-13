#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int i, j;
    bool first_row_has_zero = false, first_col_has_zero = false;
    for (i = 0; i < matrixRowSize; i++) {
        if (0 == matrix[i][0]) {
            first_col_has_zero = true;
        }
    }
    for (j = 0; j < matrixColSize; j++) {
        if (0 == matrix[0][j]) {
            first_row_has_zero = true;
        }
    }
    for (i = 0; i < matrixRowSize; i++) {
        for (j = 0; j < matrixColSize; j++) {
            if (0 == matrix[i][j]) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (i = 1; i < matrixRowSize; i++) {
        if (0 == matrix[i][0]) {
            for (j = 1; j < matrixColSize; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for (j = 1; j < matrixColSize; j++) {
        if (0 == matrix[0][j]) {
            for (i = 1; i < matrixRowSize; i++) {
                matrix[i][j] = 0;
            }
        }
    }
    if (true == first_row_has_zero) {
        for (j = 0; j < matrixColSize; j++) {
            matrix[0][j] = 0;
        }
    }
    if (true == first_col_has_zero) {
        for (i = 0; i < matrixRowSize; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    int **matrix;
    int matrixRowSize = 3;
    int matrixColSize = 3;
    int i, j;
    matrix = (int**)malloc(matrixRowSize * sizeof(int*));
    for (i = 0; i < matrixRowSize; i++) {
        matrix[i] = (int*)malloc(matrixColSize * sizeof(int));
        for (j = 0; j < matrixColSize; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }   
    setZeroes(matrix, matrixRowSize, matrixColSize);
    return 0;
}