/**
 * Use dynamic programming.Howerer,maybe memonrized searching is faster because dynamic programming still
 * has useless computing.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isScramble(char* s1, char* s2) {
    int length = strlen(s1);
    int k, i, j, n;
    bool ***f = (bool***)malloc((length + 1) * sizeof(bool**));
    for (k = 0; k <= length; k++) {
        f[k] = (bool**)malloc(length * sizeof(bool**));
        for (i = 0; i < length; i++) {
            f[k][i] = (bool*)malloc(length * sizeof(bool));
        }
    }
    for (i = 0; i < length; i++) {
        for (j = 0; j < length; j++) {
            if (s1[i] == s2[j]) {
                f[1][i][j] = true;
            } else {
                f[1][i][j] = false;
            }
        }
    }
    for (n = 2; n <= length; n++) {
        for (i = 0; i <= length - n; i++) {
            for (j = 0; j <= length - n; j++) {
                f[n][i][j] = false;
                for (k = 1; k < n; k++) {
                    f[n][i][j] = f[n][i][j] || ((f[k][i][j] && f[n - k][i + k][j + k]) || (f[k][i][j + n - k] && f[n - k][i + k][j]));
                }
            }
        }
    }
    return f[length][0][0];
}

int main() {
    char s1[] = "a";
    char s2[] = "a";
    bool result = isScramble(s1, s2);
    printf("%d", result);
    return 0;
}