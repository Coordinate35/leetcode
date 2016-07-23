int numDecodings(char* s) {
    int length = strlen(s);
    int *decoding_ways;
    int i;
    int number;
    if (0 == length) {
        return 0;
    } else if (1 == length) {
        if (('1' > s[0]) || ('9' < s[0])) {
            return 0;
        } else {
            return 1;
        }
    }
    decoding_ways = (int*)malloc(length * sizeof(int));
    if ('0' != s[0]) {
        decoding_ways[0] = 1;
    } else {
        return 0;
    }
    if ('0' != s[1]) {
        number = ((s[0] - '0') * 10 + (s[1] - '0'));
        if ((number <= 26) && (number > 0)) {
            decoding_ways[1] = 2;
        } else {
            decoding_ways[1] = 1;
        }
    } else {
        if ('2' < s[0]) {
            return 0;
        } else {
            decoding_ways[1] = 1;
        }
    }
    for (i = 2; i < length; i++) {
        if ('0' != s[i]) {
            decoding_ways[i] = decoding_ways[i - 1];
            number = ((s[i - 1] - '0') * 10 + (s[i] - '0'));
            if ((number <= 26) && (number > 9)) {
                decoding_ways[i] += decoding_ways[i - 2];
            }
        } else {
            if (('2' < s[i - 1]) || ('0' == s[i - 1])) {
                return 0;
            } else {
                decoding_ways[i] = decoding_ways[i - 2];
            }
        }
    }
    return decoding_ways[length - 1];
}