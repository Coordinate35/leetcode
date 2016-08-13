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

void dfs(struct TreeNode *current_node, int target_sum, int sum, bool* has_path_sum) {
    if (true == *has_path_sum) {
        return;
    }
    if (NULL == current_node) {
        return;
    }
    if ((NULL == current_node->left) && (NULL == current_node->right)) {
        if (sum + current_node->val == target_sum) {
            *has_path_sum = true;
        }
        return;
    }
    dfs(current_node->left, target_sum, sum + current_node->val, has_path_sum);
    dfs(current_node->right, target_sum, sum + current_node->val, has_path_sum);
}

bool hasPathSum(struct TreeNode* root, int sum) {
    bool has_path_sum = false;
    if (NULL == root) {
        return false;
    }
    dfs(root, sum, 0, &has_path_sum);
    return has_path_sum;   
}

int main() {
    struct TreeNode *current_node; 
    bool has_path_sum;
    current_node = NULL;
    has_path_sum = hasPathSum(current_node, 1);
    printf("%d\n", has_path_sum);
    return 0;
}