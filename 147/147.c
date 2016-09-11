/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode privot;
    struct ListNode *current_node;
    struct ListNode *sort_element;
    struct ListNode *sort_element_last;
    struct ListNode *next_current = head;
    struct ListNode *sort_element_tail = head;

    if (NULL == head) {
        return NULL;
    }

    privot.next = head;
    current_node = head->next;
    next_current = current_node;

    while (NULL != current_node) {
        next_current = next_current->next;
        
        sort_element_last = &privot;
        sort_element = privot.next;
        while ((current_node != sort_element) && (current_node->val > sort_element->val)) {
            sort_element_last = sort_element_last->next;
            sort_element = sort_element->next;
        }
        
        if (current_node != sort_element) {
            sort_element_tail->next = current_node->next;
            current_node->next = sort_element;
            sort_element_last->next = current_node;
        } else {
            sort_element_tail = current_node;
        }

        current_node = next_current;
    }

    return privot.next;
}