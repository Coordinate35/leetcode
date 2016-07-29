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
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode **stack;
    int *result;
    int stack_size = 0;
    int stack_pointer = 0;
    struct TreeNode *current_position = root;
    stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    result = (int*)malloc(sizeof(int));
    *returnSize = 0;  
    while ((0 != stack_pointer) || (NULL != current_position)) {
        if (NULL != current_position) {
            if (stack_pointer >= stack_size) {
                stack = realloc(stack, (stack_pointer + 1) * sizeof(struct TreeNode*));
            }
            stack[stack_pointer] = current_position;
            stack_pointer += 1;
            current_position = current_position->left;
        } else {
            stack_pointer -= 1;
            current_position = stack[stack_pointer];
            result = realloc(result, (*returnSize + 1) * sizeof(int));
            result[*returnSize] = current_position->val;
            *returnSize += 1;
            current_position = current_position->right;
        }
    }
    return result;
}