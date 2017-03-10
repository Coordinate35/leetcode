bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int sLength = strlen(s);
    bool *isBreakable = (bool*)malloc(sLength * sizeof(sLength));
    char *subString = (char*)malloc(sLength * sizeof(char));
    bool isLastSubstringBreakable;
    int i = 0;
    int j = 0;
    int k = 0;

    isBreakable[0] = false;
    for (i = 0; i < wordDictSize; ++i) {
        if ((1 == strlen(wordDict[i])) && (s[0] == wordDict[i][0])) {
            isBreakable[0] = true;
            break;
        }
    }

    for (i = 1; i < sLength; ++i) {
        isBreakable[i] = false;
        for (j = -1; j < i; ++j) {
            if (-1 == j) {
                isLastSubstringBreakable = true;
            } else {
                isLastSubstringBreakable = isBreakable[j];
            }
            if (isLastSubstringBreakable) {
                strncpy(subString, s + j + 1, i - j);
                subString[i - j] = '\0';
                for (k = 0; k < wordDictSize; ++k) {
                    if (0 == strcmp(subString, wordDict[k])) {
                        isBreakable[i] = true;
                        break;
                    }
                }
            }
        }
    }
    
    return isBreakable[sLength - 1];
}