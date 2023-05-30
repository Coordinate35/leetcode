#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void preorder(struct TreeNode *root, int *returnSize, int *result);

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int *result;
	struct TreeNode *current;

    if (root == NULL || returnSize == NULL) {
	    *returnSize = 0;
		return NULL;
    }

	result = (int*)malloc(100 * sizeof(int));
	if (result == NULL) {
	    *returnSize = 0;
	    return NULL;
	}

	*returnSize = 0;

	preorder(root, returnSize, result);
	return result;
}


void preorder(struct TreeNode *root, int *returnSize, int *result) {
    result[*returnSize] = root->val;
    *returnSize += 1;
    if (root->left != NULL) {
    	preorder(root->left, returnSize, result);
    }
  	if (root->right != NULL) {
	    preorder(root->right, returnSize, result);
	}
}


int main() {
    struct TreeNode node3 = {
	    3,
	    NULL,
	    NULL
	};
	struct TreeNode node2 = {
	    2,
	    &node3,
		NULL
	};
	struct TreeNode node1 = {
	    1,
	    NULL,
	    &node2
	};
	int size = 0;
	int i;
	int *result;
	
	result = preorderTraversal(&node1, &size);
	for (i = 0; i < size; i++) {
    	printf("%d\n", result[i]);
	}
    return 0;
}
