#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numDistinct(char* s, char* t) {
    int *f;
    int s_length = strlen(s);
    int t_length = strlen(t);
    int i, j;
    f = (int*)malloc((t_length + 2) * sizeof(int));
    f[0] = 1;
    for (i = 1; i <= t_length; i++) {
        f[i] = 0;
    }
    for (i = 0; i < s_length; i++) {
        for (j = t_length - 1; j >= 0; j--) {
            f[j + 1] += (s[i] == t[j] ? f[j] : 0);
        }
    }   
    return f[t_length];
}

int main() {
    char s[] = "CBAZTAAABBCTA";
    char t[] = "CAT";
    int result = numDistinct(s, t);
    printf("%d", result);
    return 0;
}