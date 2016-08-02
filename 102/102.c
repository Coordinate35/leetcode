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

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    struct TreeNode **queue;
    int last_layer_size = 0;
    int layer_size = 0;
    int queue_size = 0;
    int queue_head = 0;
    int i;
    int** result;
    result = (int**)malloc(sizeof(int*));
    *columnSizes = (int*)malloc(sizeof(int));
    *returnSize = 0;  
    if (NULL == root) {
        *returnSize = 0;
        return NULL;
    }
    *columnSizes = (int*)malloc(sizeof(int));
    (*columnSizes)[0] = 1;
    result[0] = (int*)malloc(sizeof(int));
    result[0][0] = root->val;
    *returnSize = 1;
    queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    queue[0] = root;
    layer_size = 1;
    queue_size = 1;
    while (0 != layer_size) {
        last_layer_size = layer_size;
        layer_size = 0;
        *columnSizes = realloc(*columnSizes, (*returnSize + 1) * sizeof(int));
        result = realloc(result, (*returnSize + 1) * sizeof(int*));
        (*columnSizes)[*returnSize] = 0;
        result[*returnSize] = (int*)malloc(sizeof(int));
        for (i = 0; i < last_layer_size; i++) {
            if (NULL != queue[queue_head]->left) {
                queue = realloc(queue, (queue_size + 1) * sizeof(struct TreeNode*));
                queue[queue_size] = queue[queue_head]->left;
                queue_size += 1;
                layer_size += 1;
                (*columnSizes)[*returnSize] +=1;
                result[*returnSize] = realloc(result[*returnSize], (*columnSizes)[*returnSize] * sizeof(int));
                result[*returnSize][(*columnSizes)[*returnSize] - 1] = queue[queue_head]->left->val;
            } 
            if (NULL != queue[queue_head]->right) {
                queue = realloc(queue, (queue_size + 1) * sizeof(struct TreeNode*));
                queue[queue_size] = queue[queue_head]->right;
                queue_size += 1;
                layer_size += 1;
                (*columnSizes)[*returnSize] +=1;
                result[*returnSize] = realloc(result[*returnSize], (*columnSizes)[*returnSize] * sizeof(int));
                result[*returnSize][(*columnSizes)[*returnSize] - 1] = queue[queue_head]->right->val;
            }
            queue_head += 1;
        }
        *returnSize += 1;
    }
    *returnSize -= 1;
    return result;
}

int main() {
    struct TreeNode nodes[7];
    int *columnSizes;
    int returnSize;
    int i, j;
    int** result;
    nodes[0].val = 3;
    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];
    nodes[1].val = 9;
    nodes[2].val = 20;
    // nodes[1].left = &nodes[3];
    // nodes[1].right = &nodes[4];
    nodes[1].left = NULL;
    nodes[1].right = NULL;
    nodes[3].val = 0;
    nodes[4].val = 2;
    nodes[3].left = NULL;
    nodes[3].right = NULL;
    nodes[4].left = NULL;
    nodes[4].right = NULL;
    nodes[2].left = &nodes[5];
    nodes[2].right = &nodes[6];
    nodes[5].val = 15;
    nodes[6].val = 7;
    nodes[5].left = NULL;
    nodes[5].right = NULL;
    nodes[6].left = NULL;
    nodes[6].right = NULL;
    result = levelOrder(&nodes[0], &columnSizes, &returnSize);
    for (i = 0; i < returnSize; i++) {
        for (j = 0; j < columnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}