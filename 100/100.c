/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void check(struct TreeNode* p, struct TreeNode* q, bool* result) {
    if (false == *result) {
        return;
    }
    if (((NULL == p) && (NULL != q)) || ((NULL != p) && (NULL == q))) {
        *result = false;
        return;
    }
    if ((NULL == p) || (NULL == q)) {
        return;
    }
    check(p->left, q->left, result);
    if (p->val != q->val) {
        *result = false;
        return;
    }
    check(p->right, q->right, result);
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    bool result = true;
    check(p, q, &result);
    return result;
}