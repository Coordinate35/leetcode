/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool is_same_tree(struct TreeNode* left_tree, struct TreeNode* right_tree) {
    bool is_left_same, is_right_same;
    if ((NULL == left_tree) && (NULL == right_tree)) {
        return true;
    }
    if ((NULL == left_tree) || (NULL == right_tree)) {
        return false;
    }
    if (left_tree->val != right_tree->val) {
        return false;
    }
    is_left_same = is_same_tree(left_tree->left, right_tree->right);
    is_right_same = is_same_tree(left_tree->right, right_tree->left);
    return is_left_same && is_right_same;
}

bool isSymmetric(struct TreeNode* root) {
    bool result;
    if (NULL == root) {
        return true;
    }
    result = is_same_tree(root->left, root->right);
    return result;
}