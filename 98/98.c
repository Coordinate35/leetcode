/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* bst_check(struct TreeNode* current, int* nums, int* numsSize) {
    if (NULL == current) {
        return nums;
    }
    nums = bst_check(current->left, nums, numsSize);
    nums = realloc(nums, (*numsSize + 1) * sizeof(int));
    nums[*numsSize] = current->val;
    *numsSize += 1;
    nums = bst_check(current->right, nums, numsSize);
    return nums;
}

bool isValidBST(struct TreeNode* root) {
    int *nums;
    int numsSize = 0;
    int i;
    nums = (int*)malloc((numsSize + 1)* sizeof(int));
    nums = bst_check(root, nums, &numsSize);
    for (i = 1; i < numsSize; i++) {
        if (nums[i] <= nums[i - 1]) {
            return false;
        }
    }
    return true;   
}

int main() {
    struct TreeNode nodes[7];
    bool result;
    nodes[0].val = 3;
    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];
    nodes[1].val = 1;
    nodes[2].val = 5;
    nodes[1].left = &nodes[3];
    nodes[1].right = &nodes[4];
    nodes[3].val = 0;
    nodes[4].val = 2;
    nodes[3].left = NULL;
    nodes[3].right = NULL;
    nodes[4].left = NULL;
    nodes[4].right = NULL;
    nodes[2].left = &nodes[5];
    nodes[2].right = &nodes[6];
    nodes[5].val = 4;
    nodes[6].val = 6;
    nodes[5].left = NULL;
    nodes[5].right = NULL;
    nodes[6].left = NULL;
    nodes[6].right = NULL;
    result = isValidBST(&nodes[0]);
    printf("%d", result);
    return 0;
}