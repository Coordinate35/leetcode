#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* count_next(char* source) {
    int i = 0, j = 0;
    int length = strlen(source);
    int current_lenth;
    char *result;
    result = (char*)malloc(sizeof(char));
    result[0] = '\0';
    while (i < length) {
        while(source[i] == source[j]) {
            j += 1;
        }
        current_lenth = strlen(result);
        result = realloc(result, (current_lenth + 3) * sizeof(char));
        result[current_lenth] = j - i + 48;
        result[current_lenth + 1] = source[i];
        result[current_lenth + 2] = '\0';
        i = j;
    }
    free(source);
    return result;
}

char* countAndSay(int n) {
    char *result;
    result = (char*)malloc(2 * sizeof(char));
    result[0] = '1';
    result[1] = '\0';
    n -= 1;
    while (n > 0) {
        result = count_next(result);
        n -= 1;
    }
    return result;  
}

int main() {
    int n = 3;
    char *result;
    result = countAndSay(n);
    puts(result);
    return 0;
}