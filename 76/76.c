#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* minWindow(char* s, char* t) {
    int start = 0, end = 0;
    int ascii_size = 256;
    int expected_char[256];
    int appeared_char[256];
    int i;
    int s_length, t_length;
    int appeared_number = 0;
    int min_start;
    int min_end;
    int origin_min_length;
    int result_length;
    char* result;
    s_length = strlen(s);
    t_length = strlen(t);
    min_start = -1;
    min_end = strlen(s) + 1;
    origin_min_length = min_end - min_start + 1;
    for (i = 0; i < ascii_size; i++) {
        expected_char[i] = 0;
        appeared_char[i] = 0;
    }
    for (i = 0; i < t_length; i++){
        expected_char[t[i]] += 1;
    }
    for (end = 0; end < s_length; end++) {
        if (0 != expected_char[s[end]]) {
            if (appeared_char[s[end]] < expected_char[s[end]]) {
                appeared_number += 1; 
            }
            appeared_char[s[end]] += 1;
        }
        if (t_length == appeared_number) {
            while ((0 == expected_char[s[start]]) || ((1 <= expected_char[s[start]]) && (expected_char[s[start]] < appeared_char[s[start]]))) {
                if (1 <= expected_char[s[start]]) {
                    appeared_char[s[start]] -= 1;
                }
                start += 1;
            }
            if (end - start < min_end - min_start) {
                min_end = end;
                min_start = start;
            }
        }
    }
    if (origin_min_length == min_end - min_start + 1) {
        return "";
    } else {
        result_length = min_end - min_start + 1;
        result = (char*)malloc((result_length + 1) * sizeof(char));
        for (i = min_start; i <= min_end; i++) {
            result[i - min_start] = s[i];
        }
        result[result_length] = '\0';
    }
    return result;
}

int main() {
    char s[] = "aabaabaaab";
    char t[] = "bb";
    char* result = minWindow(s, t);
    puts(result);
    return 0;
}