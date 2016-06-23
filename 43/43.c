#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* multiply(char* num1, char* num2)
{
    int i, j;
    int num1_length, num2_length;
    int result_state_length;
    int *int_result;
    char *result;
    if (('0' == num1[0]) || ('0' == num2[0])) {
        return "0";
    }
    num1_length = strlen(num1);
    num2_length = strlen(num2);
    result_state_length = num1_length + num2_length;
    int_result = (int*)malloc(result_state_length * sizeof(int));
    for (i = 0; i < result_state_length; i++) {
        int_result[i] = 0;
    }
    for (i = num1_length - 1; i >= 0; i--) {
        for (j = num2_length - 1; j >= 0; j--) {
            int_result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    for (i = result_state_length - 1; i > 0; i--) {
        int_result[i - 1] += int_result[i] / 10;
        int_result[i] %= 10;
    }
    result = (char*)malloc((result_state_length + 1) * sizeof(char));
    i = 0;
    if (0 == int_result[i]) {
        i += 1;
    }
    j = 0;
    while (i < result_state_length) {
        result[j] = int_result[i] + '0';
        j += 1;
        i += 1;
    }
    result[j] = '\0';
    return result;
}

int main() {
    char num1[] = "99";
    char num2[] = "99";
    char* result;
    result = multiply(num1, num2);
    puts(result);
    return 0;
}