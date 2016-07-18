/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *current = head;
    struct ListNode *temp;
    while (current != NULL) {
        while ((current->next != NULL) && (current->next->val == current->val)) {
            temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        current = current->next;
    }
    return head;
}