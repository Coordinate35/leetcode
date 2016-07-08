/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode *detector = head;
    struct ListNode *follower = head;
    int i;
    int list_length = 0;
    if (NULL == head) {
        return NULL;
    }
    for (i = 0; i < k; i++) {
        detector = detector->next;
        list_length += 1;
        if (NULL == detector) {
            detector = head;
            k %= list_length;
            i = -1;
        }
    }
    while (NULL != detector->next) {
        detector = detector->next;
        follower = follower->next;
    }
    detector->next = head;
    head = follower->next;
    follower->next = NULL;
    return head;
}