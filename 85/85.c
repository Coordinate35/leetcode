#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int largestRectangleArea(int* heights, int heightsSize) {
    int i;
    int stack_pointer = 0;
    int *stack;
    int *heights_with_zero;
    int top;
    int result = 0;
    int width;
    heightsSize += 1;
    heights_with_zero = (int*)malloc(heightsSize * sizeof(int));
    for (i = 0; i < heightsSize - 1; i++) {
        heights_with_zero[i] = heights[i];
    }
    stack = (int*)malloc(heightsSize * sizeof(int));
    heights_with_zero[heightsSize - 1] = 0;
    for (i = 0; i < heightsSize; i++) {
        if ((0 == stack_pointer) || (heights_with_zero[i] > heights_with_zero[stack[stack_pointer - 1]])) {
            stack[stack_pointer] = i;
            stack_pointer += 1;
        } else {
            while ((heights_with_zero[i] <= heights_with_zero[stack[stack_pointer - 1]]) && (stack_pointer > 0)) {
                top = stack[stack_pointer - 1];
                stack_pointer -= 1;
                if (0 == stack_pointer) {
                    width = i;
                } else {
                    width = i - stack[stack_pointer - 1] - 1;
                }
                result = max(result, heights_with_zero[top] * width);
            }
            i -= 1;
        }
    } 
    return result;
}

int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
    int *heights;
    int i, j;
    int line_result;
    int max = 0;
    heights = (int*)malloc(matrixColSize * sizeof(int));
    for (i = 0; i < matrixColSize; i++) {
        heights[i] = 0;
    }   
    for (i = 0; i < matrixRowSize; i++) {
        for (j = 0; j < matrixColSize; j++) {
            if ('0' == matrix[i][j]) {
                heights[j] = 0;
            } else {
                heights[j] += 1;
            }
        }
        line_result = largestRectangleArea(heights, matrixColSize);
        if (line_result > max) {
            max = line_result;
        } 
    }
    return max;
}

int main() {
    char **matrix;
    int matrixRowSize = 4;
    int matrixColSize = 4;
    int i, j;
    int result;
    matrix = (char**)malloc(matrixRowSize * sizeof(char*));
    for (i = 0; i < matrixRowSize; i++) {
        matrix[i] = (char*)malloc(matrixColSize * sizeof(char));
        scanf("%s", matrix[i]);
    }
    result = maximalRectangle(matrix, matrixRowSize, matrixColSize);
    printf("%d", result);
    return 0;
}