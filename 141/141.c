/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *front;
    struct ListNode *last;
    front = last = head;
    if (NULL == head) {
        return false;
    }
    while (front->next && front->next->next) {
        front = front->next->next;
        last = last->next;
        if (front == last) {
            return true;
        }
    }
    return false;
}