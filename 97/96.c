bool isInterleave(char* s1, char* s2, char* s3) {
    bool **is_inter_leave;
    int s1_length = strlen(s1);
    int s2_length = strlen(s2);
    int s3_length = strlen(s3);
    int i, j;
    if (s3_length != s1_length + s2_length) {
        return false;
    }

    is_inter_leave = (bool**)malloc((s1_length + 1) * sizeof(bool*));
    for (i = 0; i <= s1_length; i++) {
        is_inter_leave[i] = (bool*)malloc((s2_length + 1) * sizeof(bool));
    }   
    is_inter_leave[0][0] = true;
    for (i = 1; i <= s1_length; i++) {
        is_inter_leave[i][0] = (s1[i - 1] == s3[i - 1]) && is_inter_leave[i - 1][0];
    }
    for (j = 1; j <= s2_length; j++) {
        is_inter_leave[0][j] = (s2[j - 1] == s3[j - 1]) && is_inter_leave[0][j - 1];
    }

    for (i = 1; i <= s1_length; i++) {
        for (j = 1; j <= s2_length; j++) {
            is_inter_leave[i][j] = ((s1[i - 1] == s3[i + j - 1]) && is_inter_leave[i - 1][j]) || ((s2[j - 1] == s3[i + j - 1]) && is_inter_leave[i][j - 1]);
        }
    }
    return is_inter_leave[s1_length][s2_length];
}