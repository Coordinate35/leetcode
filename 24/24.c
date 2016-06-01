/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode start;
    start.next = head;
    struct ListNode *last_end;
    last_end = &start;
    struct ListNode *front, *last;
    last = head;
    if (NULL != last) {
        front = last->next;
    }
    while ((NULL != last) && (NULL != front)) {
        last_end->next = front;
        last->next = front->next;
        front->next = last;
        last_end = last;
        last = last->next;
        if (NULL != last) {
            front = last->next;
        }
    }
    return start.next;
}