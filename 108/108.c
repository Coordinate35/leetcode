/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    int middle_element = (numsSize - 1) / 2;
    struct TreeNode *current_node;
    if (0 >= numsSize) {
        return NULL;
    }   
    current_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    current_node->val = nums[middle_element];
    current_node->left = sortedArrayToBST(nums, middle_element);
    current_node->right = sortedArrayToBST(nums + middle_element + 1, numsSize - middle_element - 1);
    return current_node;
}