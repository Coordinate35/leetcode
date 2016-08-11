/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int find_depth(struct TreeNode* current_node) {
    int left_depth;
    int right_depth;
    if (NULL == current_node) {
        return 0;      
    }
    left_depth = find_depth(current_node->left);
    right_depth = find_depth(current_node->right);
    if ((1 < abs(left_depth - right_depth)) || (0 < left_depth) || (0 < right_depth)) {
        return 1;
    }
    current_node->val = min(left_depth, right_depth) - 1;
    return current_node->val;
}

bool isBalanced(struct TreeNode* root) {
    int depth = 0;
    struct TreeNode *current = root;
    depth = find_depth(root);
    if (0 < depth) {
        return false;
    } else {
        return true;
    }
}

int main() {
    struct TreeNode *root = NULL;
    bool result;
    result = isBalanced(root);
    printf("%d", result);
}