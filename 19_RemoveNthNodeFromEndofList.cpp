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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = new ListNode(0, head);
        std::unordered_map<int, ListNode*> map;
        int i = 1;
        ListNode *p = head;
        map[0] = start;
        while (p != nullptr) {
            map[i] = p;
            p = p->next;
            ++i;
        }//delete map[i-n];
        map[i-n-1]->next = map[i-n]->next;
        delete map[i-n];
        return start->next; 
    }
};