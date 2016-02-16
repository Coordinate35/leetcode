#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* run_n_step(struct ListNode* fore, int n)
{
    while (n > 0)
    {
        fore = fore->next;
        n -= 1;
    }
    return fore;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode *front, *fore;
    struct ListNode piquet;
    int i;
    if (NULL == head)
    {
        return NULL;
    }
    piquet.next = head;
    front = &piquet;
    fore = &piquet;
    fore = run_n_step(fore, n);
    while (NULL != fore->next)
    {
        fore = fore->next;
        front = front->next;
    }
    if (front->next == head)
    {
        return head->next;
    }
    front->next = front->next->next;
    return head;
}

int main()
{
    struct ListNode arr[1];
    struct ListNode *result;
    int i;
    for (i = 0; i < 1; i++)
    {
        arr[i].val = i;
        arr[i].next = arr + i + 1;
    }
    arr[i - 1].next = NULL;
    result = removeNthFromEnd(arr, 1);
    while (NULL != result)
    {
        printf("%d ", result->val);
        result = result->next;
    }
    printf("\n");
    return 0;
}
