#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isInDict(char* s, char** wordDict, int wordDictSize, int** inDict, int start, int end) {
    int i;
    int j;
    int wordLength;
    int length = end - start + 1;
    bool inDictFlag;

    if (0 == inDict[start][end]) {
        return false;
    } else if (1 == inDict[start][end]) {
        return true;
    }

    for (i = 0; i < wordDictSize; ++i) {
        inDictFlag = true;
        wordLength = strlen(wordDict[i]);
        if (wordLength != length) {
            continue;
        }
        for (j = 0; j < wordLength; ++j) {
            if (s[start + j] != wordDict[i][j]) {
                inDictFlag = false;
                break;
            }
        }
        if (true == inDictFlag) {
            inDict[start][end] = 1;
            return true;
        }
    }
    inDict[start][end] = 0;
    return false;
}

// DFS with memorized

void doWordBreak(char* s, char** wordDict, int wordDictSize, int* size, int** inDict, char*** buffer, int lastIndex) {
    int i;
    int j;
    int length = strlen(s);
    char *foreResult;
    int foreResultLength;
    int originalSize;

    i = lastIndex + 1;
    while (i != length) {
        if (isInDict(s, wordDict, wordDictSize, inDict, lastIndex + 1, i)) {
            if (-1 == size[i + 1]) {
                doWordBreak(s, wordDict, wordDictSize, size, inDict, buffer, i);
                if (-1 == size[i + 1]) {
                    size[i + 1] = 0;
                }
            }

            if (0 < size[i + 1]) {
                size[lastIndex + 1] = size[lastIndex + 1] > 0 ? size[lastIndex + 1] : 0;
                originalSize = size[lastIndex + 1];
                size[lastIndex + 1] += size[i + 1];
                buffer[lastIndex + 1] = realloc(buffer[lastIndex + 1], size[lastIndex + 1] * sizeof(char*));
                for (j = 0; j != size[i + 1]; ++j) {
                    buffer[lastIndex + 1][originalSize + j] = (char*)malloc((2 * length + 3) * sizeof(char));
                    buffer[lastIndex + 1][originalSize + j][0] = ' ';
                    foreResultLength = i - lastIndex + 1;
                    strncpy(buffer[lastIndex + 1][originalSize + j] + 1, s + lastIndex + 1, foreResultLength);
                    strncpy(buffer[lastIndex + 1][originalSize + j] + foreResultLength, buffer[i + 1][j], strlen(buffer[i + 1][j]));
                    buffer[lastIndex + 1][originalSize + j][foreResultLength + strlen(buffer[i + 1][j])] = '\0';
                }
            }

            if (i == length - 1) {
                size[lastIndex + 1] = size[lastIndex + 1] > 0 ? size[lastIndex + 1] : 0;
                buffer[lastIndex + 1] = realloc(buffer[lastIndex + 1], (size[lastIndex + 1] + 1) * sizeof(char*));
                buffer[lastIndex + 1][size[lastIndex + 1]] = (char*)malloc((2 * length + 3) * sizeof(char));
                buffer[lastIndex + 1][size[lastIndex + 1]][0] = ' ';
                strncpy(buffer[lastIndex + 1][size[lastIndex + 1]] + 1, s + lastIndex + 1, i - lastIndex);
                buffer[lastIndex + 1][size[lastIndex + 1]][i - lastIndex + 1] = '\0';
                size[lastIndex + 1] += 1;
            }
        }
        ++i;
    }
}

char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize) {
    int length = strlen(s);
    int *size = (int*)malloc((length + 1) * sizeof(int));
    char ***buffer = (char***)malloc((length + 1) * sizeof(char*));
    char **result;
    int **inDict;
    int i, j;
    int currentStringLength;

    inDict = (int**)malloc((length + 1) * sizeof(int*));
    for (i = 0; i <= length; ++i) {
        size[i] = -1;
        buffer[i] = (char**)malloc(sizeof(char*));
        buffer[i][0] = (char*)malloc((2 * length + 3) * sizeof(char));
        buffer[i][0][0] = '\0';
    }
    *returnSize = 0;
    for (i = 0; i < length; ++i) {
        inDict[i] = (int*)malloc(length * sizeof(int));
        for (j = 0; j < length; ++j) {
            inDict[i][j] = 2;
        }
    }
    /**
     * 0 for false, 1 for true, 2 for undefined
     */
    
    doWordBreak(s, wordDict, wordDictSize, size, inDict, buffer, -1);
    result = buffer[0];
    *returnSize = size[0] > 0 ? size[0] : 0;
    for (i = 0; i < *returnSize; ++i) {
        currentStringLength = strlen(result[i]);
        for (j = 1; j <= currentStringLength; ++j) {
            result[i][j - 1] = result[i][j];
        }
    }

    for (i = 0; i < length; ++i) {
        free(inDict[i]);
    }
    free(inDict);
    for (i = 1; i <= length; ++i) {
        for (j = 0; j < size[i]; ++j) {
            free(buffer[i][j]);
        }
        free(buffer[i]);
    }
    free(buffer);
    free(size);

    return result;
}

// DFS without memorization
// 
// char** doWordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize, bool** inDict, char** result, int lastIndex, int resultLastIndex) {
//     int i;
//     int j;
//     int length = strlen(s);
//     int currentLength;

//     i = lastIndex + 1;
//     while (i != length) {
//         if (isInDict(s, wordDict, wordDictSize, inDict, lastIndex + 1, i)) {
//             currentLength = strlen(result[*returnSize]);
//             if (-1 != resultLastIndex) {
//                 result[*returnSize][currentLength] = ' ';
//                 result[*returnSize][currentLength + 1] = '\0';
//                 currentLength += 1;
//             }
//             if (-1 == resultLastIndex) {
//                 result[*returnSize][0] = '\0';
//             }
//             strncpy(result[*returnSize] + strlen(result[*returnSize]), s + lastIndex + 1, i - lastIndex);
//             result[*returnSize][currentLength + i - lastIndex] = '\0';
//             if (i == length - 1) {
//                 *returnSize += 1;
//                 result = realloc(result, (*returnSize + 1) * sizeof(char*));
//                 result[*returnSize] = (char*)malloc((2 * length + 1) * sizeof(char));
//                 strcpy(result[*returnSize], result[*returnSize - 1]);
//                 result[*returnSize][strlen(result[*returnSize - 1])] = '\0';
//             } else {
//                 result = doWordBreak(s, wordDict, wordDictSize, returnSize, inDict, result, i, strlen(result[*returnSize]) - 1);
//             }
//             result[*returnSize][resultLastIndex + 1] = '\0';
//         }
//         ++i;
//     }
//     return result;
// }

// char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize) {
//     int length = strlen(s);
//     char **result = (char**)malloc(sizeof(char*));
//     int **inDict;
//     int i, j;
//     inDict = (int**)malloc(length * sizeof(int*));
//     for (i = 0; i < length; ++i) {
//         inDict[i] = (int*)malloc(length * sizeof(int));
//         for (j = 0; j < length; ++j) {
//             inDict[i][j] = 2;
//         }
//     }
//     /**
//      * 0 for false, 1 for true, 2 for undefined
//      */

//     *returnSize = 0;
//     result[0] = (char*)malloc((2 * length + 1) * sizeof(char));
//     result[0][0] = '\0';
    
//     result = doWordBreak(s, wordDict, wordDictSize, returnSize, inDict, result, -1, -1);
    
//     for (i = 0; i < length; ++i) {
//         free(inDict[i]);
//     }
//     free(inDict);

//     return result;
// }

int main() {
    // char s[] = "catsanddog";
    // char s1[] = "cat";
    // char s2[] = "cats";
    // char s3[] = "and";
    // char s4[] = "sand";
    // char s5[] = "dog";

    // char s[] = "aggegbnngohbggalojckbdfjakgnnjadhganfdkefeddjdnabmflabckflfljafdlmmbhijojiaaifedaihnoinedhhnolcjdam";
    // char s1[] = "aggegbnngohbgga";

    // char s[] = "cbca";
    // char s1[] = "bc";
    // char s2[] = "ca";

    // char s[] = "acccbccb";
    // char s1[] = "cc";
    // char s2[] = "bc";
    // char s3[] = "ac";
    // char s4[] = "ca";

    char s[] = "a";
    // char s1[] = "a";

    // char s[] = "aaaaaaa";
    // char s1[] = "aaaa";
    // char s2[] = "aaa";

    int wordDictSize = 0;
    char **wordDict = (char**)malloc(wordDictSize * sizeof(char*));
    char **result;
    int returnSize;
    int i;
    for (i = 0; i < wordDictSize; ++i) {
        wordDict[i] = (char*)malloc(wordDictSize * sizeof(char));
    }
    // wordDict[0] = (char*)s1;
    // wordDict[1] = (char*)s2;
    // wordDict[2] = (char*)s3;
    // wordDict[3] = (char*)s4;
    // wordDict[4] = (char*)s5;
    result = wordBreak(s, wordDict, wordDictSize, &returnSize);
    for (i = 0; i < returnSize; ++i) {
        puts(result[i]);
    }

    return 0;
}