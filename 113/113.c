/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int** dfs(struct TreeNode* current_node, int target_sum, int current_sum, int size, int** columnSizes, int* returnSize, int** result) {
    int i;
    if (NULL == current_node) {
        return result;
    }
    result[*returnSize] = realloc(result[*returnSize], (size + 1) * sizeof(int));
    result[*returnSize][size] = current_node->val;
    size += 1;
    if ((NULL == current_node->left) && (NULL == current_node->right)) {
        if (current_sum + current_node->val == target_sum) {
            (*columnSizes)[*returnSize] = size;
            *returnSize += 1;
            *columnSizes = realloc(*columnSizes, (*returnSize + 1) * sizeof(int));
            result = realloc(result, (*returnSize + 1) * sizeof(int*));
            result[*returnSize] = (int*)malloc((*columnSizes)[*returnSize - 1] * sizeof(int));
            for (i = 0; i < (*columnSizes)[*returnSize - 1]; i++) {
                result[*returnSize][i] = result[*returnSize - 1][i];
            }
        }
        return result;
    }
    result = dfs(current_node->left, target_sum, current_sum + current_node->val, size, columnSizes, returnSize, result);
    result = dfs(current_node->right, target_sum, current_sum + current_node->val, size, columnSizes, returnSize, result);
    return result;
}

int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize) {
    int current_sum = 0;
    int **result;
    *returnSize = 0;
    *columnSizes = (int*)malloc(sizeof(int)); 
    result = (int**)malloc(sizeof(int*));
    result[0] = (int*)malloc(sizeof(int));
    result = dfs(root, sum, current_sum, 0, columnSizes, returnSize, result);
    return result;
}

int main() {
    struct TreeNode root;
    root.val = 1;
    root.left = NULL;
    root.right = NULL;
    int sum = 1;
    int* columnSizes;
    int returnSize;
    int** result;
    int i, j;
    result = pathSum(&root, sum, &columnSizes, &returnSize);
    for (i = 0; i < returnSize; i++) {
        for (j = 0; j < columnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// [5,4,8,11,null,13,4,7,2,null,null,5,1]
// 22