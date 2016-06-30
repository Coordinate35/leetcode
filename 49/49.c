/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculate_hash(char *a, int l, int r) {
    char privot = a[l];
    int i, j;
    char temp;
    j = l;
    if (l < r) { 
        for (i = l; i <= r; i++) {
            if (a[i] < privot) {
                temp = a[j];
                a[j] = a[i];
                a[i] = a[j + 1];
                a[j + 1] = temp;
                j++;
            }
        }
        calculate_hash(a, l, j - 1);
        calculate_hash(a, j + 1, r);
    }
}

void quicksort(char** strs, char** hash, int l, int r) {
    char* privot;
    privot = hash[l];
    char* temp;
    int i, j;
    j = l;
    if (l < r) {
        for (i = l; i <= r; i++) {
            if (0 > strcmp(hash[i], privot)) {
                temp = hash[j];
                hash[j] = hash[i];
                hash[i] = hash[j + 1];
                hash[j + 1] = temp;
                temp = strs[j];
                strs[j] = strs[i];
                strs[i] = strs[j + 1];
                strs[j + 1] = temp;
                j++;
            }
        }
        quicksort(strs, hash, l, j - 1);
        quicksort(strs, hash, j + 1, r);
    }
}

char* hash(char* str) {
    char* result;
    int length;
    int i;
    length = strlen(str);
    result = (char*)malloc((length + 1) * sizeof(char));
    for (i = 0; i < length; i++) {
        result[i] = str[i];
    }
    result[length] = '\0';
    calculate_hash(result, 0, length - 1);
    return result;
}

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
    int i;
    char** hash_value;
    char*** result;
    if (0 == strsSize) {
        return NULL;
    }
    *returnSize = 0;
    result = (char***)malloc(sizeof(char**));
    result[0] = (char**)malloc(sizeof(char*)); 
    *columnSizes = (int*)malloc(sizeof(int));
    hash_value = (char**)malloc(strsSize * sizeof(char*));
    for (i = 0; i < strsSize; i++) {
        hash_value[i] = hash(strs[i]);
    }
    quicksort(strs, hash_value, 0, strsSize - 1);
    result[0][0] = strs[0];
    (*columnSizes)[0] = 1;
    for (i = 1; i < strsSize; i++) {
        if (0 != strcmp(hash_value[i], hash_value[i - 1])) {
            *returnSize += 1;
            result = realloc(result, (*returnSize + 1) * sizeof(char**));
            result[*returnSize] = (char**)malloc(sizeof(char*));
            *columnSizes = realloc(*columnSizes, (*returnSize + 1) * sizeof(int));
            (*columnSizes)[*returnSize] = 0;
        }
        (*columnSizes)[*returnSize] += 1;
        result[*returnSize] = realloc(result[*returnSize], ((*columnSizes)[*returnSize] + 1) * sizeof(char*));
        result[*returnSize][(*columnSizes)[*returnSize] - 1] = strs[i]; 
    }
    *returnSize += 1;
    return result;
}

int main() {
    char **str;
    str = (char**)malloc(6 * sizeof(char*));
    str[0] = (char*)malloc(4 * sizeof(char));
    str[1] = (char*)malloc(4 * sizeof(char));
    str[2] = (char*)malloc(4 * sizeof(char));
    str[3] = (char*)malloc(4 * sizeof(char));
    str[4] = (char*)malloc(4 * sizeof(char));
    str[5] = (char*)malloc(4 * sizeof(char));
    str[0][0] = 'e';
    str[0][1] = 'a';
    str[0][2] = 't';
    str[0][3] = '\0';
    str[1][0] = 't';
    str[1][1] = 'e';
    str[1][2] = 'a';
    str[1][3] = '\0';
    str[2][0] = 't';
    str[2][1] = 'a';
    str[2][2] = 'n';
    str[2][3] = '\0';
    str[3][0] = 'a';
    str[3][1] = 't';
    str[3][2] = 'e';
    str[3][3] = '\0';
    str[4][0] = 'n';
    str[4][1] = 'a';
    str[4][2] = 't';
    str[4][3] = '\0';
    str[5][0] = 'b';
    str[5][1] = 'a';
    str[5][2] = 't';
    str[5][3] = '\0';
    int strsSize = 6;
    int* columnSizes;
    int returnSize;
    char ***result;
    result = groupAnagrams(str, strsSize, &columnSizes, &returnSize);
    return 0;
}