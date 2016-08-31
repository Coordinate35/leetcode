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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode* node, int current_sum, int* total_sum) {
    current_sum = 10 * current_sum + node->val;
    if ((NULL == node->left) && (NULL == node->right)) {
        *total_sum += current_sum;
        return;
    }
    if (NULL != node->left) {
        dfs(node->left, current_sum, total_sum);
    }
    if (NULL != node->right) {
        dfs(node->right, current_sum, total_sum);
    }
}

int sumNumbers(struct TreeNode* root) {
    int sum = 0;
    if (NULL == root) {
        return 0;
    }
    dfs(root, 0, &sum);
    return sum;
}

int main() {
    int sum;
    struct TreeNode node1, node2;
    node1.val = 1;
    node1.left = &node2;
    node1.right = NULL;
    node2.val = 2;
    node2.left = NULL;
    node2.right = NULL;
    sum = sumNumbers(&node1);
    printf("%d", sum);
    return 0;
}