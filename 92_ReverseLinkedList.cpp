#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = 1;
        ListNode *start, *p, *q, *r;
        start = new ListNode(0, head);
        while (count < left) {
            ++count;
            start = start->next;
        }
        p = start->next;
        while (count < right) {
            q = p->next;
            r = start->next;
            start->next = q;
            p->next = q->next;
            q->next = r;
            ++count;
        }
        if (left == 1) {
            return start->next;
        } else {
            return head;
        }
    }
};