/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode *current, int current_depth, int *depth) {
    if (current_depth > *depth) {
        *depth = current_depth;
    }
    if (NULL != current->left) {
        dfs(current->left, current_depth + 1, depth);
    }
    if (NULL != current->right) {
        dfs(current->right, current_depth + 1, depth);
    }
}

int maxDepth(struct TreeNode* root) {
    int depth = 0;
    if (NULL == root) {
        return 0;
    }
    dfs(root, 1, &depth);
    return depth;
}