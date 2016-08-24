char to_lower_case(char a) {
    int distance = 'a' - 'A';
    if (('A' <= a) && ('Z' >= a)) {
        return a + distance;
    }
    return a;
}

bool is_valid(char a) {
    if ((('a' <= a) && ('z' >= a)) || (('A' <= a) && ('Z' >= a)) || (('0' <= a) && ('9' >= a))) {
        return true;
    }
    return false;
}

bool isPalindrome(char* s) {
    int s_length = strlen(s);
    int front = -1;
    int end = s_length;
    if (0 == s_length) {
        return true;
    }
    while ((front + 1 < s_length) && ( ! is_valid(s[front + 1]))) {
        front += 1;
    }
    while ((end - 1 >= 0) && ( ! is_valid(s[end - 1]))) {
        end -= 1;
    }
    front += 1;
    end -= 1;
    while (front < end) {
        if (to_lower_case(s[front]) != to_lower_case(s[end])) {
            return false;
        }
        while ((front + 1 < s_length) && ( ! is_valid(s[front + 1]))) {
            front += 1;
        }
        while ((end - 1 >= 0) && ( ! is_valid(s[end - 1]))) {
            end -= 1;
        }
        front += 1;
        end -= 1;
    }
    return true;
}