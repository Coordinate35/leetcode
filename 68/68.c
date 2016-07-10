/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** add_one_line(char** result, int current_size, int line_length) {
    result = realloc(result, (current_size + 1) * sizeof(char*));
    result[current_size] = (char*)malloc((line_length + 1) * sizeof(char));
    result[current_size][line_length] = '\0';
    return result;
}

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char** result;
    int last = -1;
    int current = -1;
    int container = 0;
    int space_number;
    int space_segment_number;
    int current_space_segment_number;
    int item_index;
    int i, j;
    int word_length;
    if (0 == wordsSize) {
        return NULL;
    }
    *returnSize = 0;   
    result = (char**)malloc(0);
    result = add_one_line(result, *returnSize, maxWidth);
    while (last < wordsSize - 1) {
        container = 0;
        space_number = maxWidth;
        item_index = 0;
        while ((current + 1 < wordsSize) && (container + strlen(words[current + 1]) <= maxWidth - (current - last))) {
            current += 1;
            container += strlen(words[current]);
            space_number -= strlen(words[current]);
        }
        space_segment_number = current - last - 1;
        if (current != wordsSize - 1) {
            for (i = last + 1; i < current; i++) {
                word_length = strlen(words[i]);
                for (j = 0; j < word_length; j++) {
                    result[*returnSize][item_index] = words[i][j];
                    item_index += 1;
                }  
                if (0 == space_number % space_segment_number) {
                    current_space_segment_number = space_number / space_segment_number;
                } else {
                    current_space_segment_number = space_number / space_segment_number + 1;
                }
                space_number -= current_space_segment_number;
                space_segment_number -= 1;
                for (j = 0; j < current_space_segment_number; j++) {
                    result[*returnSize][item_index] = ' ';
                    item_index += 1;
                }
            }
            word_length = strlen(words[current]);
            for (j = 0; j < word_length; j++) {
                result[*returnSize][item_index] = words[current][j];
                item_index += 1;
            }
            while (item_index < maxWidth) {
                result[*returnSize][item_index] = ' ';
                item_index += 1;
            }
            *returnSize += 1;
            result = add_one_line(result, *returnSize, maxWidth);
            last = current;
        } else {
            for (i = last + 1; i < current; i++) {
                word_length = strlen(words[i]);
                for (j = 0; j < word_length; j++) {
                    result[*returnSize][item_index] = words[i][j];
                    item_index += 1;
                }
                result[*returnSize][item_index] = ' ';
                item_index += 1;
            }
            word_length = strlen(words[current]);
            for (j = 0; j < word_length; j++) {
                result[*returnSize][item_index] = words[current][j];
                item_index += 1;
            }
            while (item_index < maxWidth) {
                result[*returnSize][item_index] = ' ';
                item_index += 1;
            }
            *returnSize += 1;
            last = current;
        }
    }
    return result;
}

int main() {
    char **words;
    int maxWidth = 14;
    int wordsSize = 7;
    int i;
    int returnSize;
    char** result;
    words = (char**)malloc(wordsSize * sizeof(char*));
    for (i = 0; i < wordsSize; i++) {
        words[i] = (char*)malloc((maxWidth + 1) * sizeof(char));
        scanf("%s", words[i]);
    }
    result = fullJustify(words, wordsSize, maxWidth, &returnSize);
    return 0;
}