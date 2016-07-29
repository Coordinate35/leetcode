/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void substr(char* s, char* destination, int from, int until) {
    int i;
    for (i = from; i < until; i++) {
        destination[i - from] = s[i];
    }
    destination[i - from] = '\0';
}

bool is_ip_segment(char* s) {
    if (strlen(s) > 3) {
        return false;
    } 
    if (('0' == s[0]) && (strlen(s) > 1)) {
        return false;
    }
    if (atoi(s) > 255) {
        return false;
    }
    return true;
}

char** restoreIpAddresses(char* s, int* returnSize) {
    char **result;
    char *ip_segment;
    int ip_uplimit = 255;
    int s_length = strlen(s); 
    int spliter_number = 3;
    int result_length = s_length + spliter_number + 1;
    int *split_position = (int*)malloc((spliter_number + 1) * sizeof(int));
    int current_spliter;
    int i;
    int added_dot_number;
    bool is_back = false;
    current_spliter = 1;
    *returnSize = 0;
    result = (char**)malloc(sizeof(char*));
    split_position[0] = 0;
    split_position[1] = 0;
    ip_segment = (char*)malloc(s_length * sizeof(char));
    while ((split_position[1] <= s_length - spliter_number + 1) && (split_position[0] == 0)) {
        split_position[current_spliter] += 1;
        while ((current_spliter > 0) && ((split_position[current_spliter] > 3 * current_spliter) || (split_position[current_spliter] >= s_length))) {
            current_spliter -= 1;
            split_position[current_spliter] += 1;
        }
        if (-1 == current_spliter) {
            return result;
        }
        if ((split_position[1] >= s_length - spliter_number + 1) && (split_position[0] != 0)) {
            return result;
        }
        substr(s, ip_segment, split_position[current_spliter - 1] , split_position[current_spliter]);
        if (false == is_ip_segment(ip_segment)) {
            current_spliter -= 1;
        } else {
            if (spliter_number == current_spliter) {
                substr(s, ip_segment, split_position[current_spliter], s_length);
                if (true == is_ip_segment(ip_segment)) {
                    result = realloc(result, (*returnSize + 1) * sizeof(char*));
                    result[*returnSize] = (char*)malloc(result_length * sizeof(char));
                    added_dot_number = 0;
                    for (i = 0; i < s_length; i++) {
                        if (i == split_position[added_dot_number + 1]) {
                            result[*returnSize][i + added_dot_number] = '.';
                            added_dot_number += 1;
                        }
                        result[*returnSize][i + added_dot_number] = s[i];
                    }
                    result[*returnSize][i + added_dot_number] = '\0';
                    *returnSize += 1;
                }
            } else {
                split_position[current_spliter + 1] = split_position[current_spliter];
                current_spliter += 1;
            }
        }
    }
    return result;
}

int main() {
    int returnSize;
    int i;
    char** result;
    char s[] = "2736786374048";
    result = restoreIpAddresses(s, &returnSize);
    for (i = 0; i < returnSize; i++) {
        puts(result[i]);
    }
    return 0;
}