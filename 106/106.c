/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    struct TreeNode *current_node;
    int order = 0;
    if (0 >= inorderSize) {
        return NULL;
    }   
    while (postorder[postorderSize - 1] != inorder[order]) {
        order += 1;
    }
    current_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    current_node->val = postorder[postorderSize - 1];
    current_node->left = buildTree(inorder, order, postorder, order);
    current_node->right = buildTree(inorder + order + 1, inorderSize - order - 1, postorder + order, inorderSize - order - 1);
    return current_node;
}