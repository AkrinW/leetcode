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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *start = new ListNode(-1000, head);
        ListNode *p = start;
        ListNode *q = head;
        while (q != nullptr && q->next != nullptr) {
            if (q->next->val != q->val) {
                p = p->next;
                q = q->next;
            } else {
                int v = q->val;
                while (q != nullptr && v == q->val) {
                    ListNode *tmp = q;
                    q = q->next;
                    delete tmp;
                }
                p->next = q;
            }
        }
        return start->next;
    }
};