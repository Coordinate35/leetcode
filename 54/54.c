/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    bool **judge;
    int i, j;
    int col = 0, row = 0;
    int size;
    int *result;
    size = matrixColSize * matrixRowSize;
    result = (int*)malloc(size * sizeof(int));
    for (i = 0; i < size; i++) {
        result[i] = -1;
    }
    judge = (bool**)malloc(matrixRowSize * sizeof(bool*));
    for (i = 0; i < matrixRowSize; i++) {
        judge[i] = (bool*)malloc(matrixColSize * sizeof(bool));
        for (j = 0; j < matrixColSize; j++) {
            judge[i][j] = true;
        }
    }
    if (0 == size) {
        return NULL;
    }
    result[0] = matrix[0][0]; 
    judge[0][0] = false;
    for (i = 1; i < size;) {
        if ((col + 1 < matrixColSize) && (true == judge[row][col + 1])) {
            while ((col + 1 < matrixColSize) && (true == judge[row][col + 1])) {
                col += 1;
                result[i] = matrix[row][col];
                judge[row][col] = false;
                i += 1;
            }
        } else if ((row + 1 < matrixRowSize) && (true == judge[row + 1][col])) {
            while ((row + 1 < matrixRowSize) && (true == judge[row + 1][col])) {
                row += 1;
                result[i] = matrix[row][col];
                judge[row][col] = false;
                i += 1;
            }
        } else if ((col - 1 >= 0) && (true == judge[row][col - 1])) {
            while ((col - 1 >= 0) && (true == judge[row][col - 1])) {
                col -= 1;
                result[i] = matrix[row][col];
                judge[row][col] = false;
                i += 1;
            }
        } else if ((row - 1 >= 0) && (true == judge[row - 1][col])) {
            while ((row - 1 >= 0) && (true == judge[row - 1][col])) {
                row -= 1;
                result[i] = matrix[row][col];
                judge[row][col] = false;
                i += 1;
            }
        }
    }
    return result;
}

int main() {
    int **matrix;
    int matrixRowSize = 4;
    int matrixColSize = 4;
    int i, j;
    int *result;
    matrix = (int**)malloc(matrixRowSize * sizeof(int*));
    for (i = 0; i < matrixRowSize; i++) {
        matrix[i] = (int*)malloc(matrixColSize * sizeof(int));
        for (j = 0; j < matrixColSize; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    result = spiralOrder(matrix, matrixRowSize, matrixColSize);
    return 0;
}