#include <stdio.h>
#include <stdlib.h>

struct ListNode {
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

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int i;
    struct ListNode* result;
    if (0 == listsSize) {
    	return NULL;
    }
    if (1 == listsSize) {
    	return lists[0];
    }
    result = lists[0];
    for (i = 1; i < listsSize; i++) {
    	result = mergeTwoLists(result, lists[i]);
    }
    return result;
}

int main() {
	int listsSize;
	struct ListNode** lists;
	struct ListNode* result;
	listsSize = 2;
	lists = (struct ListNode**)malloc(listsSize * sizeof(struct ListNode*));
	lists[0] = (struct ListNode*)malloc(2 * sizeof(struct ListNode));
	lists[0]->val = 2;
	lists[0]->next = lists[0] + 1;
	lists[0]->next->val = 8;
	lists[0]->next->next = NULL;
	lists[1] = (struct ListNode*)malloc(1 * sizeof(struct ListNode));
	lists[1]->val = 5;
	lists[1]->next = NULL;
	result = mergeKLists(lists, listsSize);
	while (NULL != result) {
		printf("%d\n", result->val);
		result = result->next;
	}
	return 0;
}