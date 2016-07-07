/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int** generateMatrix(int n) {
    int** matrix;
    bool** matrix_flag;
    int row, col;
    int count = 1;
    int target = n * n;
    matrix = (int**)malloc(n * sizeof(int*));
    matrix_flag = (bool**)malloc(n * sizeof(bool*));
    for (row = 0; row < n; row++) {
        matrix[row] = (int*)malloc(n * sizeof(int));
        matrix_flag[row] = (bool*)malloc(n * sizeof(bool));
        for (col = 0; col < n; col++) {
            matrix_flag[row][col] = true;
        }
    }
    row = 0;
    col = -1;
    while (count <= target) {
        if ((col + 1 < n) && (true == matrix_flag[row][col + 1])) {
            while ((true == matrix_flag[row][col + 1]) && (col + 1 < n)) {
                col += 1;
                matrix[row][col] = count;
                matrix_flag[row][col] = false;
                count += 1;
            }
        } else if ((row + 1 < n) && (true == matrix_flag[row + 1][col])) {
            while ((row + 1 < n) && (true == matrix_flag[row + 1][col])) {
                row += 1;
                matrix[row][col] = count;
                matrix_flag[row][col] = false;
                count += 1;
            }
        } else if ((col - 1 >= 0) && (true == matrix_flag[row][col - 1])) {
            while ((col - 1 >= 0) && (true == matrix_flag[row][col - 1])) {
                col -= 1;
                matrix[row][col] = count;
                matrix_flag[row][col] = false;
                count += 1;
            }
        } else if ((row - 1 >= 0) && (true == matrix_flag[row - 1][col])) {
            while ((row - 1 >= 0) && (true == matrix_flag[row - 1][col])) {
                row -= 1;
                matrix[row][col] = count;
                matrix_flag[row][col] = false;
                count += 1;
            }
        }
    }
    return matrix;
}