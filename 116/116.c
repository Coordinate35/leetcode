/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    struct TreeLinkNode *current;
    struct TreeLinkNode *next_line = root;
    if (NULL == root) {
        return;
    }   
    while (NULL != next_line->left) {
        current = next_line;
        while (NULL != current) {
            current->left->next = current->right;
            if (NULL != current->next) {
                current->right->next = current->next->left;
            }
            current = current->next;
        }
        next_line = next_line->left;
    }
}