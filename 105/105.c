/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    struct TreeNode *current_node; 
    int order;
    if (0 >= preorderSize) {
        return NULL;
    }    
    order = 0;
    while (preorder[0] != inorder[order]) {
        order += 1;
    }
    current_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    current_node->val = preorder[0];
    current_node->left = buildTree(preorder + 1, order, inorder, order);
    current_node->right = (buildTree(preorder + order + 1, preorderSize - order - 1, inorder + order + 1, preorderSize - order - 1));
    return current_node;
}