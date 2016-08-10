/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedListToBST(struct ListNode* head) {
    int number = 0;
    int middle;
    int counter;
    struct ListNode *detector = head;
    struct TreeNode *current;
    struct ListNode *last;
    struct ListNode privot;
    if (NULL == head) {
        return NULL;
    }
    privot.next = head;
    last = &privot;
    current = head;
    while (NULL != detector) {
        detector = detector->next;
        number += 1;
    }
    middle = number / 2;
    counter = middle;
    detector = head;
    current = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    while (counter > 0) {
        detector = detector->next;
        last = last->next;
        counter -= 1;
    }
    last->next = NULL;
    current->val = detector->val;
    if (0 == middle) {
        current->left = NULL;
    } else {
        current->left = sortedListToBST(head);
    }
    current->right = sortedListToBST(detector->next);
    return current;
}