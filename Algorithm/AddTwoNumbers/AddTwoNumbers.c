#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int d = 0, r = 0;
    struct ListNode* tmp = NULL;
    struct ListNode* cur = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode* head = cur;
    d = l1->val + l2->val;
    r = d / 10;
    d %= 10;
    head->val = d;
    head->next = NULL;
    
    l1 = l1->next;
    l2 = l2->next;
        
    while (l1 || l2) {
        tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (l1 && l2) {
            d = l1->val + l2->val + r;
            r = d / 10;
            d %= 10;
            tmp->val = d;
            tmp->next = NULL;
            l1 = l1->next;
            l2 = l2->next;
        } else if ((l1 != NULL) && (l2 == NULL)) {
            d = l1->val + r;
            r = d / 10;
            d %= 10;
            tmp->val = d;
            tmp->next = NULL;
            l1 = l1->next;
        } else if ((l1 == NULL) && (l2 != NULL)) {
            d = l2->val + r;
            r = d / 10;
            d %= 10;
            tmp->val = d;
            tmp->next = NULL;
            l2 = l2->next;
        }
        
        cur->next = tmp;
        cur = tmp;
    }
    
    if (r != 0) {
        tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp->val = r;
        tmp->next = NULL;
        cur->next = tmp;
    }
    return head;
}