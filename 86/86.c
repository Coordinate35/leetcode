#include <stdio.h>
#include <stdlib.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 }; 

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *less_link = NULL;
    struct ListNode *more_link = NULL;
    struct ListNode *less_current = NULL;
    struct ListNode *more_current = NULL;
    struct ListNode *last = NULL;
    int i;  
    while (NULL != head) {
        if (head->val < x) {
            if (NULL == less_current) {
                less_current = (struct ListNode*)malloc(sizeof(struct ListNode));
                less_link = less_current;
                less_current->next = NULL;
            } else {
                less_current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                less_current = less_current->next;
                less_current->next = NULL;
            }
            less_current->val = head->val;
        } else {
            if (NULL == more_current) {
                more_current = (struct ListNode*)malloc(sizeof(struct ListNode));
                more_link = more_current;
                more_current->next = NULL;
            } else {
                more_current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                more_current = more_current->next;
                more_current->next = NULL;
            }
            more_current->val = head->val;
        }
        last = head;
        head = head->next;
        // free(last);
    }
    if (NULL == less_current) {
        less_link = more_link;
    } else {
        less_current->next = more_link;
    }
    return less_link;
}

int main() {
    int size = 1;
    int i;
    int target = 0;
    struct ListNode* head;
    struct ListNode* current;
    struct ListNode* result;
    for (i = 0; i < size; i++) {
        if (NULL == current) {
            current = (struct ListNode*)malloc(sizeof(struct ListNode));
            current->next = NULL;
            head = current;
        } else {
            current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            current = current->next;
            current->next = NULL;
        }
        scanf("%d", &current->val);
    }
    result = partition(head, target);
    return 0;
}