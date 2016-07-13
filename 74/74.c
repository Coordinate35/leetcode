bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int left, right, middle;
    int row = -1;
    left = 0;
    right = matrixRowSize - 1;
    while (-1 == row) {
        if (left > right) {
            return false;
        }
        if (right == left) {
            if ((target <= matrix[left][matrixColSize - 1]) && (target >= matrix[left][0])) {
                row = left;
            } else {
                return false;
            }
        }
        if (-1 == row) {
            middle = (right + left) / 2;
            if (target < matrix[middle][0]) {
                right = middle - 1;
            } else if (target > matrix[middle][matrixColSize -1]) {
                left = middle + 1;
            } else {
                row = middle;
            }
        }
    }   
    left = 0;
    right = matrixColSize - 1;
    while (right >= left) {
        if (right == left) {
            if (matrix[row][left] == target) {
                return true;
            } else {
                return false;
            }
        }
        middle = (left + right) / 2;
        if (matrix[row][middle] > target) {
            right = middle - 1;
        } else if (matrix[row][middle] < target) {
            left = middle + 1;
        } else {
            return true;
        }
    }
    return false;
}