#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct leaf_root_sum_tree_node {
    int val;
    struct leaf_root_sum_tree_node *left;
    struct leaf_root_sum_tree_node *right;
    struct TreeNode *original_node;
};

int two_max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int three_max(int a, int b, int c) {
    if (a > b) {
        return two_max(a, c);
    } else {
        return two_max(b, c); 
    }
}

void dfs_form_tree(struct leaf_root_sum_tree_node *new_tree_root, struct TreeNode *original_tree_root) {
    struct leaf_root_sum_tree_node *new_tree_node;
    new_tree_root->original_node = original_tree_root;
    if (NULL != original_tree_root->left) {
        new_tree_node = (struct leaf_root_sum_tree_node*)malloc(sizeof(struct leaf_root_sum_tree_node));
        new_tree_node->left = NULL; 
        new_tree_node->right = NULL;
        new_tree_root->left = new_tree_node;
        dfs_form_tree(new_tree_root->left, original_tree_root->left);
    }
    if (NULL != original_tree_root->right) {
        new_tree_node = (struct leaf_root_sum_tree_node*)malloc(sizeof(struct leaf_root_sum_tree_node));
        new_tree_node->left = NULL; 
        new_tree_node->right = NULL;
        new_tree_root->right = new_tree_node;
        dfs_form_tree(new_tree_root->right, original_tree_root->right);
    }
}

int calculate_max_path_from_leaf_to_node(struct leaf_root_sum_tree_node* root) {
    int max_left_path = INT_MIN;
    int max_right_path = INT_MIN;
    int max_path;
    if (NULL == root) {
        return INT_MIN;
    }
    max_left_path = calculate_max_path_from_leaf_to_node(root->left);
    max_right_path = calculate_max_path_from_leaf_to_node(root->right);
    max_path = two_max(max_left_path, max_right_path);
    root->val = (0 > max_path ? 0 : max_path) + root->original_node->val;
    return root->val;
}

int find_max_path_in_subtree(struct leaf_root_sum_tree_node* root) {
    int max_left = 0;
    int max_right = 0;
    int max_path_in_left_subtree = INT_MIN;
    int max_path_in_right_subtree = INT_MIN;
    int max_path_through_current_node = 0;
    if (NULL != root->left) {
        max_left = root->left->val;
        max_path_in_left_subtree = find_max_path_in_subtree(root->left);
    }
    if (NULL != root->right) {
        max_right = root->right->val;
        max_path_in_right_subtree = find_max_path_in_subtree(root->right);
    }
    max_path_through_current_node = (0 > max_left ? 0 : max_left) + (0 > max_right ? 0 : max_right) + root->original_node->val;
    return three_max(max_path_through_current_node, max_path_in_left_subtree, max_path_in_right_subtree);
}

int maxPathSum(struct TreeNode* root) {
    struct leaf_root_sum_tree_node new_root;
    int max_path_sum_from_leaf_to_root;
    if (NULL == root) {
        return INT_MIN;
    }
    new_root.left = NULL;
    new_root.right = NULL;
    dfs_form_tree(&new_root, root);
    max_path_sum_from_leaf_to_root = calculate_max_path_from_leaf_to_node(&new_root);
    return find_max_path_in_subtree(&new_root);   
}

int main() {
    struct TreeNode n1, n2;
    int sum;
    n1.val = -3;
    n1.left = NULL;
    n1.right = NULL;
    sum = maxPathSum(&n1);
    printf("%d", sum);
    return 0;
}