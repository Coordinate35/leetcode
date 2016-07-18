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

int main() {
    int heights[] = {2,1,4,5,6,3};
    int heightsSize = 6;
    int result = largestRectangleArea(heights, heightsSize);
    printf("%d", result); 
    return 0;
}