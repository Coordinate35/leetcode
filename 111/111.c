/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode *current_node, int* min_depth, int current_depth) {
    if (NULL == current_node) {
        return;
    }
    current_depth += 1;
    if ((NULL == current_node->left) && (NULL == current_node->right)) {
        if (current_depth < *min_depth) {
            *min_depth = current_depth;
        }
        return;
    }
    dfs(current_node->left, min_depth, current_depth);
    dfs(current_node->right, min_depth, current_depth);
}

int minDepth(struct TreeNode* root) {
    int min_depth = INT_MAX;
    if (NULL == root) {
        return 0;
    }
    dfs(root, &min_depth, 0);
    return min_depth;   
}