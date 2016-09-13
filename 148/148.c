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

// void quicksort(struct ListNode* privot, int length) {
//     struct ListNode *current_node = privot;
//     struct ListNode *sorted_tail = privot;
//     int left_length = 0;
//     int temp;
//     int standard;
    
//     if (0 < length) {
//         standard = privot->next->val;
//         while (NULL != current_node->next) {
//             current_node = current_node->next;
//             if (current_node->val < standard) {
//                 left_length += 1;
//                 temp = sorted_tail->next->val;
//                 sorted_tail->next->val = current_node->val;
//                 current_node->val = sorted_tail->next->next->val;
//                 sorted_tail->next->next->val = temp;
//                 sorted_tail = sorted_tail->next;
//             }
//         }
//         quicksort(privot, left_length);
//         quicksort(sorted_tail->next, length - left_length - 1);
//     }
// }

// struct ListNode* sortList(struct ListNode* head) {
//     struct ListNode privot;
//     int length = 0;
//     struct ListNode *current_node = head;
//     privot.next = head;
//     while (NULL != current_node) {
//         length += 1;
//         current_node = current_node->next;
//     }
//     quicksort(&privot, length);
//     return privot.next;
// }

struct ListNode* merge_two_sorted_list(struct ListNode* left_list, int left_length, struct ListNode* right_list, int right_length) {
    struct ListNode *head;
    struct ListNode *tail;
    struct ListNode privot;
    
    if (0 == left_length) {
        return right_list; 
    }
    
    head = &privot;
    tail = head;
    while ((0 != left_length) && (0 != right_length)) {
        if (left_list->val < right_list->val) {
            tail->next = left_list;
            tail = tail->next;
            left_list = left_list->next;
            left_length -= 1;
        } else {
            tail->next = right_list;
            tail = tail->next;
            right_list = right_list->next;
            right_length -= 1;
        }
    }
    if (0 == left_length) {
        tail->next = right_list;
    } else {
        tail->next = left_list;
    }

    return head->next;
}

struct ListNode* merge_sort(struct ListNode* head, int length) {
    int left_length = length / 2;
    int right_length = length - left_length;
    int i;
    struct ListNode *left_list, *right_list;
    struct ListNode *result;

    if (0 == length) {
        return NULL;
    } else if (1 == length) {
        head->next = NULL;
        return head;
    }

    right_list = head;
    for (i = 0; i < left_length; i++) {
       right_list = right_list->next; 
    }


    left_list = head;
    left_list = merge_sort(left_list, left_length);
    right_list = merge_sort(right_list, right_length);
    result = merge_two_sorted_list(left_list, left_length, right_list, right_length);
    return result;
}

struct ListNode* sortList(struct ListNode* head) {
    int length = 0;
    struct ListNode *current_node = head;
    struct ListNode *result;
    while (NULL != current_node) {
        length += 1;
        current_node = current_node->next;
    }
    result = merge_sort(head, length);
    return result;
}

int main() {
    struct ListNode *head = NULL;
    struct ListNode *result;
    result = sortList(head);
    return 0;
}