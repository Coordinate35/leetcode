int min(int a, int b, int c) {
    if (a < b) {
        if (a < c) {
            return a;
        } else {
            return c;
        }
    } else {
        if (b < c) {
            return b;
        } else {
            return c;
        }
    }
}

int minDistance(char* word1, char* word2) {
    int **result;
    int i, j;
    int word1_length = strlen(word1);
    int word2_length = strlen(word2); 
    result = (int**)malloc((strlen(word1) + 1) * sizeof(int*));
    for (i = 0; i <= word1_length; i++){
        result[i] = (int*)malloc((strlen(word2) + 1) * sizeof(int));
    }   
    for (i = 1; i <= word1_length; i++) {
        result[i][0] = i;
    }
    for (i = 1; i <= word2_length; i++) {
        result[0][i] = i;
    }
    for (i = 0; i < word1_length; i++) {
        for (j = 0; j < word2_length; j++) {
            if (word1[i] == word2[j]) {
                result[i + 1][j + 1] = result[i][j];
            } else {
                result[i + 1][j + 1] = 1 + min(result[i][j], result[i][j + 1], result[i + 1][j]);
            }
        }
    }
    return result[word1_length][word2_length];
}