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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *start, *current;
    if (NULL == l1)
    {
        return l2;
    }
    if (NULL == l2)
    {
        return l1;
    }
    start = (struct ListNode*)malloc(sizeof(struct ListNode));
    current = start;
    while ((NULL != l1) && (NULL != l2))
    {
        if (l1->val < l2->val)
        {
            current->next = l1;
            l1 = l1->next;
        }
        else
        {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    current->next = NULL == l1 ? l2 : l1;
    return start->next;
}

/**
struct ListNode* form_list(int* array, int length)
{
    int i;
    struct ListNode *list, *p;
    list = (struct ListNode*)malloc((length + 1) * sizeof(struct ListNode));
    p = list;
    for (i = 0; i < length; i++)
    {
        p->val = array[i];
        p->next = p + 1;
        p += 1;
    }
    p -= 1;
    p->next = NULL;
    return list;
}

int main()
{
    struct ListNode *list1, *list2, *result;
    int array1 = {2, 5, 7};
    int array2 = {3, 4};
    list1 = form_list(list1, 3);
    list2 = form_list(list2, 2);
    result = mergeTwoLists(list1, list2);
    while (NULL != result->next)
    {
        printf("%d ", result->val);
        result += 1;
    }
    printf("%d\n", result->val);
    return 0;
}
*/
