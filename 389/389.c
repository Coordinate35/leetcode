int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

void quicksort(char* nums, int l, int r) {
    char privot = nums[l];
    int i, j;
    char temp;
    j = l;
    if (l < r) {
        for (i = l; i <= r; i++) {
            if (nums[i] < privot) {
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = nums[j + 1];
                nums[j + 1] = temp;
                j += 1;
            }
        }
        quicksort(nums, l, j - 1);
        quicksort(nums, j + 1, r);
    } 
}

char findTheDifference(char* s, char* t) {
    int s_length = strlen(s);
    int t_length = strlen(t);
    quicksort(s, 0, s_length - 1);
    quicksort(t, 0, t_length - 1);
    int j = min(s_length, t_length) - 1;
    int i;
    for (i = 0; i <= j; i++ ) {
        if (s[i] != t[i]) {
            if (s_length > t_length)  {
                return s[i];
            } else {
                return t[i];
            }
        }
    }
    if (s_length > t_length) {
        return s[s_length - 1];
    } else {
        return t[t_length - 1];
    }
}