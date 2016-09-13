/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void quicksort(struct ListNode* privot, int length) {
    struct ListNode *current_node = privot;
    struct ListNode *sorted_tail = privot;
    int left_length = 0;
    int temp;
    int standard;
    
    if (0 < length) {
        standard = privot->next->val;
        while (NULL != current_node->next) {;
            current_node = current_node->next;
            if (current_node->val < standard) {
                left_length += 1;
                temp = sorted_tail->next->val;
                sorted_tail->next->val = current_node->val;
                current_node->val = sorted_tail->next->next->val;
                sorted_tail->next->next->val = temp;
                sorted_tail = sorted_tail->next;
            }
        }
        quicksort(privot, left_length);
        quicksort(sorted_tail->next, length - left_length - 1);
    }
}

struct ListNode* sortList(struct ListNode* head) {
    struct ListNode privot;
    int length = 0;
    struct ListNode *current_node = head;
    privot.next = head;
    while (NULL != current_node) {
        length += 1;
        current_node = current_node->next;
    }
    quicksort(&privot, length);
    return privot.next;
}

int main() {
    struct ListNode *head = NULL;
    struct ListNode *result;
    result = sortList(head);
    return 0;
}