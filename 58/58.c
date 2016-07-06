int lengthOfLastWord(char* s) {
    int length;
    int count = 0;
    length = strlen(s);
    while (s[length - 1] == ' ') {
        length -= 1;
    }
    while ((length > 0) && (s[length - 1] != ' ')) {
        count += 1;
        length -= 1;
    }   
    return count;
}