/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int A_length = 0;
    int B_length = 0;
    int distance;
    struct ListNode *a_pointer = headA;
    struct ListNode *b_pointer = headB;
    while (NULL != a_pointer) {
        A_length += 1;
        a_pointer = a_pointer->next;
    }
    while (NULL != b_pointer) {
        B_length += 1;
        b_pointer = b_pointer->next;
    }
    if ((0 == A_length) || (0 == B_length) || (a_pointer != b_pointer)) {
        return NULL;
    }
    a_pointer = headA;
    b_pointer = headB;
    distance = A_length - B_length;
    if (distance > 0) {
        while (distance > 0) {
            a_pointer = a_pointer->next;
            distance -= 1;
        }
    } else {
        while (distance < 0) {
            b_pointer = b_pointer->next;
            distance += 1;
        }
    }
    while (NULL != a_pointer) {
        if (a_pointer == b_pointer) {
            return a_pointer;
        }
        a_pointer = a_pointer->next;
        b_pointer = b_pointer->next;
    }
    return NULL;
}