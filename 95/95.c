/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */


struct TreeNode** generate(int start, int end, int* returnSize) {
    int k, i, j;
    int left_size, right_size;
    struct TreeNode **left_tree, **right_tree, **result;
    result = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    if (start > end) {
        result[0] = NULL;
        *returnSize = 1;
        return result;
    }
    *returnSize = 0;
    for (k = start; k <= end; k++) {
        left_tree = generate(start, k - 1, &left_size);
        right_tree = generate(k + 1, end, &right_size);
        for (i = 0; i < left_size; i++) {
            for (j = 0; j < right_size; j++) {
                result = realloc(result, (*returnSize + 1) * sizeof(struct TreeNode*));
                result[*returnSize] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                result[*returnSize]->val = k;
                result[*returnSize]->left = left_tree[i];
                result[*returnSize]->right = right_tree[j];
                *returnSize += 1;
            }
        }
    }
    return result;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    if (0 == n) {
        *returnSize = 0;
        return NULL;
    }
    return generate(1, n, returnSize); 
}