int numTrees(int n) {
    int *tree_number;
    int i, j;
    tree_number = (int*)malloc((n + 1) * sizeof(int));
    if (0 <= n) {
        tree_number[0] = 1;
    }   
    if (1 <= n) {
        tree_number[1] = 1;
    }
    for (i = 2; i <= n; i++) {
        for (j = 0; j <= i - 1; j++) {
            tree_number[i] += tree_number[j] * tree_number[i - j - 1];
        } 
    }
    return tree_number[n];
}