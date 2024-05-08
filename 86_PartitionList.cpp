#include <iostream>
#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *smallHead = new ListNode(0);
        ListNode *bigHead = new ListNode(0);
        ListNode *p = smallHead, *q = bigHead;
        ListNode *i = head;
        while (i != nullptr) {
            if (i->val < x) {
                p->next = i;
                p = p->next;
            } else {
                q->next = i;
                q = q->next;
            }
            i = i->next;
        }
        if (bigHead->next != nullptr) {
            p->next = bigHead->next;
            q->next = nullptr;
            return p;
        } else {
            return bigHead->next;
        }
    }
};