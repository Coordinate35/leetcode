/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int i;
    struct ListNode **k_group;
    struct ListNode start;
    struct ListNode *last_end, *current;
    if (NULL == head) {
        return NULL;
    }
    last_end = &start;
    start.next = head;
    current = head;
    k_group = (struct ListNode **)malloc(sizeof(struct ListNode*) * k);
    while (true) {
        for (i = 0; i < k; i++) {
            if (NULL == current) {
                return start.next;
            }
            k_group[i] = current;
            current = current->next; 
        }
        k_group[0]->next = k_group[k - 1]->next; 
        for (i = k - 1; i > 0; i--) {
            k_group[i]->next = k_group[i - 1];
        }
        last_end->next = k_group[k - 1];
        last_end = k_group[0];
    }
}