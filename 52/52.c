#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool check(int* queen, int size, int row, int col) {
    int i;
    for (i = 0; i < row; i++) {
        if ((queen[i] == col) || (abs(i - row) == abs(queen[i] - col))) {
            return false;
        }
    }
    return true;
}

int totalNQueens(int n) {
    int i, j;
    int *queen;
    int row = 0;
    int col = 0;
    int return_size = 0;
    if (1 == n) {
        return 1;
    }
    queen = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        queen[i] = -1;
    }
    while ((row != 0) || (col != n)) {
        while (n == col) {
            row -= 1;
            col = queen[row] + 1;
        }
        if (-1 == row) {
            return return_size;
        }
        if (true == check(queen, n, row, col)) {
            queen[row] = col;
            if (n - 1 == row) {
                row -= 1;
                col = queen[row] + 1;
                return_size += 1;
            } else {
                row += 1;
                col = 0;
            }
        } else {
            col += 1;
        }
    }
    return return_size;
}

int main() {
    int n = 1;
    int result;
    result = totalNQueens(n);
    printf("%d", result);
    return 0;
}