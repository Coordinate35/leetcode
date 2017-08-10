void reorderList(struct ListNode *head) {
    int length = 0;
    int mid, i, j;
    struct ListNode *front, *front_probe, *tail, *mid_node;
    struct ListNode *p = head;
    if (!head) {
        return;
    }
    while (p) {
        p = p->next;
        length += 1;
    }
    mid = (length + 1) / 2 - 1;
    mid_node = head;
    for (i = 1; i <= mid; ++i) {
        mid_node = mid_node->next;
    }
    front = head;
    tail = mid_node;
    for (i = 0; i < length - 1; ++i) {
        if (i % 2 == 0) {
            for (j = (length - i) / 2; j > 0; --j) {
                tail = tail->next;
            }
            front_probe = front->next;
            front->next = tail;
            front = front_probe;
        } else {
            tail->next = front;
            tail = mid_node;
        }
    }
    front->next = NULL;
}