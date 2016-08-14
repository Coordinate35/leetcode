/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    struct TreeNode *temp;
    if (NULL == root) {
        return;
    }   

    flatten(root->left);
    flatten(root->right);

    if (NULL == root->left) {
        return;
    }

    temp = root->left;
    while (NULL != temp->right) {
        temp = temp->right;
    }
    temp->right = root->right;
    root->right = root->left;
    root->left = NULL;
}