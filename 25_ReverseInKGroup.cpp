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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 1;
        ListNode *found = head, *start = new ListNode(0, head), *p = start;
        while (found != nullptr) {
            if (count == k) {
                found = start->next;
                count = 0;
                start = reverseBetween(start, 2, k + 1);
                start = found;
            } else {
                ++count;
                found = found->next;
            }
        }
        return p->next;
    }
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