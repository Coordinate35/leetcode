/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void check(struct TreeNode **first, struct TreeNode **second, struct TreeNode *previous_node, struct TreeNode *current_node) {
    if ((NULL != previous_node) && (previous_node->val > current_node->val)) {
        if (NULL == *first) {
            *first = previous_node;
        }
        *second = current_node;
    }
}

void recoverTree(struct TreeNode* root) {
    struct TreeNode *previous_node = NULL;
    struct TreeNode *current_node = root;
    struct TreeNode *first = NULL, *second = NULL;
    struct TreeNode *explorer = NULL;
    int temp;
    while (NULL != current_node) {
        if (NULL == current_node->left) {
            check(&first, &second, previous_node, current_node);
            previous_node = current_node;
            current_node = current_node->right;
        } else {
            explorer = current_node->left;
            while ((NULL != explorer->right) && (current_node != explorer->right)) {
                explorer = explorer->right;
            }
            if (NULL == explorer->right) {
                explorer->right = current_node;
                current_node = current_node->left;
            } else {
                check(&first, &second, previous_node, current_node);
                explorer->right = NULL; // Without this line: Time Limit Exceeded
                previous_node = current_node;
                current_node = current_node->right;
            }
        }
    }

    temp = first->val;
    first->val = second->val;
    second->val = temp;
}