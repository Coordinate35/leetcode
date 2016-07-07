#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int factorial(int n) {
    int result = 1;
    if (0 == n) {
        return n;
    }
    while (n > 1) {
        result *= n;
        n -= 1;
    }
    return result;
}

char* getPermutation(int n, int k) {
    char* kth_permutaion;
    bool* numbers;
    int i, j;
    int rest_bit;
    int rest_number;
    int need_position;
    int delete_block;
    int n_bit_permutation_number;
    int char_int_distance = '0';
    numbers = (bool*)malloc((n + 1) * sizeof(bool));
    kth_permutaion = (char*)malloc((n + 1) * sizeof(char));
    kth_permutaion[n] = '\0';
    numbers[0] = false;
    for (i = 1; i <= n; i++) {
        numbers[i] = true;
    }
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            for (j = 1; j <= n; j++) {
                if (true == numbers[j]) {
                    kth_permutaion[i] = j + char_int_distance;
                    return kth_permutaion;
                }
            }
        }
        rest_bit = n - i;
        rest_number = factorial(rest_bit);
        need_position = 0;
        while ((need_position + 1) * (rest_number / rest_bit) < k) {
            need_position += 1;
        }
        delete_block = need_position;
        j = 1;
        while (false == numbers[j]) {
            j += 1;
        } 
        for (; delete_block > 0; j++) {
            if (true == numbers[j]) {
                delete_block -= 1;
            }
            while ((j + 1 < n) && (false == numbers[j + 1])) {
                j += 1;
            }
        }
        kth_permutaion[i] = j + char_int_distance; 
        numbers[j] = false;
        k -= need_position * (rest_number / rest_bit);
    }
    return kth_permutaion;
}

int main() {
    int n = 3;
    int k = 5;
    char *kth_permutaion = getPermutation(n, k);
    return 0;
}