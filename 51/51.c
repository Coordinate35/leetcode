/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char*** init(char*** result, int index, int size) {
    int i, j;
    result = realloc(result, (index + 1) * sizeof(char**));
    result[index] = (char**)malloc(size * sizeof(char*));
    for (i = 0; i < size; i++) {
        result[index][i] = (char*)malloc((size + 1) * sizeof(char));
        for (j = 0; j < size; j++) {
            result[index][i][j] = '.';
        }
        result[index][i][size] = '\0';
    }
    return result;
}

bool check(int* queen, int size, int row, int col) {
    int i;
    for (i = 0; i < row; i++) {
        if ((queen[i] == col) || (abs(i - row) == abs(queen[i] - col))) {
            return false;
        }
    }
    return true;
}

void add_solution(char*** result, int index, int *queen, int size) {
    int i;
    for (i = 0; i < size; i++) {
        result[index][i][queen[i]] = 'Q';
    }
}

char*** solveNQueens(int n, int* returnSize) {
    char*** result;
    int i, j;
    int* queen;
    int row = 0;
    int col = 0;
    queen = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        queen[i] = -1;
    }
    *returnSize = 0;
    result = (char***)malloc(sizeof(char**));
    result = init(result, 0, n);
    while ((row != 0) || (col != n)) {
        while (n == col) {
            row -= 1;
            col = queen[row] + 1;
        }
        if (-1 == row) {
            return result;
        }
        if (true == check(queen, n, row, col)) {
            queen[row] = col;
            if (n - 1 == row) {
                add_solution(result, *returnSize, queen, n);
                row -= 1;
                col = queen[row] + 1;
                *returnSize += 1;
                result = init(result, *returnSize, n);
            } else {
                row += 1;
                col = 0;
            }
        } else {
            col += 1;
        }
    }
    return result;
}

int main() {
    int n, returnSize;
    char*** result;
    n = 5;
    result = solveNQueens(n, &returnSize);
    return 0;
}