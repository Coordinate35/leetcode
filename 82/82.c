#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
	int current_val;
	struct ListNode * current;
	struct ListNode * last;
	struct ListNode start;
	start.next = head;
	last = &start;
	while (NULL != last->next) {
		current = last->next;
		current_val = current->val;
		while ((NULL != current->next) && (current->next->val == current->val)) {
			current = current->next;
		}
		if (current != last->next) {
			if (last->next == head) {
				head = current->next;
			}
			last->next = current->next;
		}
		else
		{
			last = current;
		}
	}
	return head;
}

int main() {
	return 0;
}