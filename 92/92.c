/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode *from;
    struct ListNode *from_next;
    struct ListNode *privot;
    struct ListNode *last_from_next;
    struct ListNode privot_node;
    int reverse_number = n - m;
    if (m == n) {
        return head;
    }
    from = head;
    privot = &privot_node;
    privot->next = head;
    from_next = from->next;
    while (m > 1) {
        from = from->next;
        privot = privot->next;
        m -= 1;
        n -= 1;
    }
    while (n > m) {
        if (n - m == reverse_number) {
            last_from_next = from;
        } else {
            last_from_next = from_next;
        }
        from_next = from->next;
        from->next = from_next->next;
        from_next->next = last_from_next;
        n -= 1;
    }
    privot->next = from_next;
    return privot_node.next;
}