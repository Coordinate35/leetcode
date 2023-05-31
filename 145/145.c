#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};


void postorder(struct TreeNode *root, int *returnSize, int *result) {
  if (root->left != NULL) {
	postorder(root->left, returnSize, result);
  }
  if (root->right != NULL) {
	postorder(root->right, returnSize, result);
  }
  result[*returnSize] = root->val;
  *returnSize += 1;
}


int* postorderTraversal(struct TreeNode* root, int* returnSize) {
  int *result;

  *returnSize = 0;
  if (root == NULL) {
	return NULL;
  }
  
  result = (int*)malloc(100 * sizeof(int));
  if (result == NULL) {
	return NULL;
  }

  postorder(root, returnSize, result);
  return result;
}
