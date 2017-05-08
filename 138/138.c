/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    struct RandomListNode *copyNode;
    struct RandomListNode *originalNode = head;
    struct RandomListNode *copyLinkHead;

    if ( ! head) {
        return NULL;
    }

    while (originalNode) {
        copyNode = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
        copyNode->label = originalNode->label;
        copyNode->next = NULL;
        copyNode->random = NULL;
        copyNode->next = originalNode->next;
        originalNode->next = copyNode;
        originalNode = copyNode->next;
    }

    originalNode = head;
    while (originalNode) {
        if (originalNode->random) {
            originalNode->next->random = originalNode->random->next;
        }
        originalNode = originalNode->next->next;
    }

    originalNode = head;
    copyLinkHead = originalNode->next;
    while (originalNode) {
        copyNode = originalNode->next;
        originalNode->next = copyNode->next;
        originalNode = copyNode->next;
        if (originalNode) {
            copyNode->next = originalNode->next;
        }
    }

    return copyLinkHead;
}