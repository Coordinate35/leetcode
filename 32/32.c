#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestValidParentheses(char* s) {
    int length = strlen(s);
    int *longest_end, *stack;
    int i, stack_pointer, max;
    stack_pointer = 0;
    max = 0;
    longest_end = (int*)malloc(length * sizeof(int));
    stack = (int*)malloc(length * sizeof(int));
    for (i = 0; i < length; i++) {
        longest_end[i] = 0;
        stack[i] = 0;
    } 
    for (i = 0; i < length; i++) {
        if ('(' == s[i]) {
            stack[stack_pointer] = i;
            stack_pointer += 1;
        } else if (stack_pointer > 0) {
            stack_pointer -= 1;
            longest_end[i] = i - stack[stack_pointer] + 1;
            if (0 < stack[stack_pointer]) {
                longest_end[i] += longest_end[stack[stack_pointer] - 1];
            }
        }
        if (max < longest_end[i]) {
            max = longest_end[i];
        }
    }
    return max;
}

int main() {
    // char s[] = "()(((()))()())()";
    char s[] = "()";
    int result = longestValidParentheses(s);
    printf("%d\n", result);
    return 0;
}