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
    struct ListNode *meet = NULL;
    int loopLength = 1;
    int notLoopLength = 0;
    int i;
    bool finded = false;

    front = last = head;
    if (NULL == head) {
        return NULL;
    }
    while ((front->next) && (front->next->next)) {
        front = front->next->next;
        last = last->next;
        if (front == last) {
            meet = front;
        }
    }
    if (NULL == meet) {
        return NULL;
    }
    front = meet->next;
    while (meet != front) {
        front = front->next;
        loopLength += 1;
    }
    last = head;
    while ( ! finded) {
        front = last;
        for (i = 0; i < loopLength; i++) {
            front = front->next;
        }
        if (front == last) {
            finded = true;
        }
        last = last->next;
    }
    
    return NULL;
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