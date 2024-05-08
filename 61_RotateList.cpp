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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *start = new ListNode(0, head);
        ListNode *p = head;
        std::unordered_map<int, ListNode*> map;
        int i = 0;
        while (p != nullptr) {
            ++i;
            map[i] = p;
            p = p->next;
        }
        map[i+1] = map[1];
        if (i != 0) {
            int b = k % i;
            map[i]->next = map[1];
            map[i-b]->next = nullptr;
            start->next = map[i-b+1];
        }
        return start->next;
    }
};