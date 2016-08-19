/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left, *right, *next;
};

struct TreeLinkNode* find_next_line_start(struct TreeLinkNode* current){
    while (NULL != current) {
        if (NULL != current->left) {
            return current->left;
        }        
        if (NULL != current->right) {
            return current->right;
        }
        current = current->next;
    }
    return NULL;
}

void connect(struct TreeLinkNode *root) {
    struct TreeLinkNode *current;
    struct TreeLinkNode *next_line = root;
    struct TreeLinkNode *from;
    if (NULL == root) {
        return;
    }   
    while (NULL != find_next_line_start(next_line)) {
        current = next_line;
        while ((NULL != current) && (NULL == current->left) && (NULL == current->right)) {
            current = current->next;
        }
        from = NULL != current->left ? current->left : current->right;
        if ((NULL != current->right) && (from != current->right)) {
            from->next = current->right;
            from = current->right;
        }
        current = current->next;
        while (NULL != current) {
            if (NULL != current->left) {
                from->next = current->left;
                from = current->left;
            }
            if (NULL != current->right) {
                from->next = current->right;
                from = current->right;
            }
            current = current->next;
        }
        next_line = find_next_line_start(next_line);
    }
}

int main() {
    struct TreeLinkNode node1, node2, node3, node4, node5;
    node1.val = 3;
    node2.val = 9;
    node3.val = 20;
    node4.val = 15;
    node5.val = 7;
    node1.left = &node2;
    node1.right = &node3;
    node3.left = &node4;
    node3.right = &node5;
    node2.left = node1.next = node2.right = node2.next = node3.next = node4.left = node4.right = node4.next = node5.left = node5.right = node5.next = NULL;
    connect(&node1);
    return 0; 
}