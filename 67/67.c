#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* strver(char* str) {
    int length = strlen(str);
    int half_length = length / 2;
    int i;
    char temp;
    for (i = 0; i < half_length; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    return str;
}

char* addBinary(char* a, char* b) {
    int a_length = strlen(a);
    int b_length = strlen(b);
    char* temp;   
    char* result;
    int i;
    int common_length;
    int longer_length;
    if (strlen(a) > strlen(b)) {
        temp = b;
        b = a;
        a = temp;
    }
    common_length = strlen(a);
    longer_length = strlen(b);
    result = (char*)malloc(2 * longer_length * sizeof(char));
    for (i = 0; i < 2 * longer_length; i++) {
        result[i] = '0';
    }
    a = strver(a);
    b = strver(b);
    for (i = 0; i < common_length; i++) {
        result[i + 1] += ((result[i] - '0') + (a[i] - '0') + (b[i] - '0')) / 2;
        result[i] = ((result[i] - '0') + (a[i] - '0') + (b[i] - '0')) % 2 + '0';  
    }
    while (i < longer_length) {
        result[i + 1] += ((result[i] - '0') + (b[i] - '0')) / 2;
        result[i] = ((result[i] - '0') + (b[i] - '0')) % 2 + '0';
        i += 1;
    }
    while (result[i] >= '2') {
        result[i + 1] += (result[i] - '0') / 2;
        result[i] = (result[i] - '0') % 2 + '0';
        i += 1;
    }
    if ('0' == result[i]) {
        result[i] = '\0';
    } else {
        result[i + 1] = '\0';
    }
    result = strver(result);
    return result;
}

int main() {
    char a[] = "1";
    char b[] = "11";
    char* result = addBinary(a, b);
    return 0;
}