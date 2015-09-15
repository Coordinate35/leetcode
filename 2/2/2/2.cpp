#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	int bit;
	struct ListNode *l1_pointer, *l2_pointer, *result_pointer, *result_head, *rest_pointer, *followed_pointer;
	l1_pointer = l1;
	l2_pointer = l2;
	bit = 0;
	result_head = (struct ListNode*)malloc(sizeof(struct ListNode));
	result_head->next = NULL;
	result_pointer = result_head;
	result_pointer->val = (l1_pointer->val + l2_pointer->val) % 10;
	bit = (l1_pointer->val + l2_pointer->val) / 10;
	l1_pointer = l1_pointer->next;
	l2_pointer = l2_pointer->next;
	free(l1);
	free(l2);
	while ((NULL != l1_pointer) && (NULL != l2_pointer))
	{
		result_pointer->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		result_pointer = result_pointer->next;
		result_pointer->next = NULL;
		l1 = l1_pointer;
		l2 = l2_pointer;
		result_pointer->val = (l1_pointer->val + l2_pointer->val + bit) % 10;
		bit = (l1_pointer->val + l2_pointer->val + bit) / 10;
		l1_pointer = l1_pointer->next;
		l2_pointer = l2_pointer->next;
		free(l1);
		free(l2);
	}
	if (NULL == l1_pointer)
	{
		rest_pointer = l2_pointer;
	}
	else
	{
		rest_pointer = l1_pointer;
	}
	while (NULL != rest_pointer)
	{
		result_pointer->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		result_pointer = result_pointer->next;
		result_pointer->next = NULL;
		result_pointer->val = (rest_pointer->val + bit) % 10;
		bit = (rest_pointer->val + bit) / 10;
		followed_pointer = rest_pointer;
		rest_pointer = rest_pointer->next;
		free(followed_pointer);
	}
	if (0 != bit)
	{
		result_pointer->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		result_pointer = result_pointer->next;
		result_pointer->next = NULL;
		result_pointer->val = bit;
	}
	return result_head;
}

struct ListNode* form_list(int list)
{
	struct ListNode *head, *p;
	head    = (struct ListNode*)malloc(sizeof(struct ListNode));
	p       = head;
	p->val  = list % 10;
	p->next = NULL;
	list /= 10;
	while (0 != list)
	{
		p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		p       = p->next;
		p->val  = list % 10;
		p->next = NULL;
		list /= 10;
	}
	return head;
}

void show_list(struct ListNode *result)
{
	while (NULL != result->next)
	{
		printf("%d ", result->val);
		result = result->next;
	}
	printf("%d", result->val);
}

int main()
{
	int list1, list2;
	struct ListNode *l1, *l2, *result;
	scanf_s("%d%d", &list1, &list2);
	l1 = form_list(list1);
	l2 = form_list(list2);
	result = addTwoNumbers(l1, l2);
	show_list(result);
	getchar();
	getchar();
	return 0;
}