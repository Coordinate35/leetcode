#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *front;
    struct ListNode *last;
    struct ListNode *first_meeting_node;
    front = last = head;
    first_meeting_node = NULL;
    if (NULL == head) {
        return NULL;
    }
    while ((front->next) && (front->next->next)) {
        front = front->next->next;
        last = last->next;
        if (front == last) {
            first_meeting_node = front;
            break;
        }
    }
    if (NULL == first_meeting_node) {
        return NULL;
    }
    front = head;
    last = first_meeting_node;
    while (front != last) {
        front = front->next;
        last = last->next;
    }
    return front;
}

int main() {
    struct ListNode head;
    struct ListNode *result;
    head.val = 1;
    head.next = NULL;

    result = detectCycle(&head);
    printf("%d\n", 5);
    return 0;
}