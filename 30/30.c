#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dict {
    int number;
    char* word;
};

struct dict* count(char** words, int wordsSize, int* uniq_word_number) {
    int i, j;
    struct dict *dictionary;
    *uniq_word_number = 1;
    dictionary = (struct dict *)malloc(sizeof(struct dict));
    dictionary[0].word = words[0];
    dictionary[0].number = 1;
    for (i = 1; i < wordsSize; i++) {
        for (j = 0; j < *uniq_word_number; j++) {
            if (0 == strcmp(dictionary[j].word, words[i])) {
                dictionary[j].number += 1;
                break;
            }
        }
        if (j == *uniq_word_number) {
            *uniq_word_number += 1;
            dictionary = realloc(dictionary, (*uniq_word_number) * sizeof(struct dict));
            dictionary[*uniq_word_number - 1].word = words[i];
            dictionary[*uniq_word_number - 1].number = 1;
        }
    }
    return dictionary;
}

void reset_counter(struct dict* dictionary, struct dict* counter, int size) {
    int i;
    for (i = 0; i < size; i++) {
        counter[i].word = dictionary[i].word;
        counter[i].number = dictionary[i].number;
    }
}

void substring(char* segment, char* s, int start, int to) {
    int i;
    for (i = start; i <= to; i++) {
        segment[i - start] = s[i];
    }
    segment[to - start + 1] = '\0';
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int *result;
    int uniq_word_number, i, loop_edge, j, counter_index, s_index, word_length, k;
    *returnSize = 0;
    struct dict *dictionary, *counter;
    char* segment;
    result = (int*)malloc(sizeof(int));
    dictionary = count(words, wordsSize, &uniq_word_number);
    counter = (struct dict *)malloc(uniq_word_number * sizeof(struct dict));
    loop_edge = strlen(s) - strlen(words[0]) * wordsSize;
    word_length = strlen(words[0]);
    segment = (char*)malloc((word_length + 1) * sizeof(char));
    for (i = 0; i <= loop_edge; i++) {
        reset_counter(dictionary, counter, uniq_word_number);
        j = wordsSize;
        s_index = i;
        while (j > 0) {
            for (counter_index = 0; counter_index < uniq_word_number; counter_index++){
                substring(segment, s, s_index, s_index + word_length - 1);
                if (0 == strcmp(segment, counter[counter_index].word)) {
                    break;
                }
            }
            if (counter_index == uniq_word_number) {
                break;
            } else {
                if (0 == counter[counter_index].number) {
                    break;
                } else {
                    counter[counter_index].number -= 1;
                    j -= 1;
                    s_index += word_length;
                    if (0 == j) {
                        *returnSize += 1;
                        result = realloc(result, (*returnSize) * sizeof(int));
                        result[*returnSize - 1] = i;
                        break;
                    }
                }
            }
        }
    }
    return result;              
}

int main() {
    int *result, returnSize, i;
    char s[] = "barfoothefoobarman";
    char* words[] = {"bar", "foo"};
    int wordsSize = 2;
    result = findSubstring(s, words, wordsSize, &returnSize);
    for (i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}