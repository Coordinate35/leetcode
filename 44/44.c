bool isMatch(char* s, char* p) {
    char *last_p = NULL, *last_s = NULL;
    while (*s) {
        if (('?' == *p) || (*s == *p)) {
            s += 1;
            p += 1;
            continue;
        }
        if ('*' == *p) {
            last_p = p;
            p++;
            last_s = s;
            continue;
        }
        if (last_p) {
            p = last_p + 1;
            last_s += 1;
            s = last_s;
            continue;
        }
        return false;
    }       
    while ('*' == *p) {
        p += 1;
    }
    return !*p;
}