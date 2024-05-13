#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int num = 0;
        ListNode *start = new ListNode(0,head);
        ListNode *sortStart = start;   
        ListNode *sortp = start->next;
        ListNode *sortq = sortp;
        while (sortp != nullptr) {
            ++num;
            sortp = sortp->next;
        }
        sortp = start->next;
        int i = 1;
        while (i < num) {
            for (int j = i ; j > 0; --j) {
                sortq = sortq->next;
                if (sortq == nullptr) {
                    break;
                }
            }
            if (sortq == nullptr) {
                sortStart = start;
                sortp = start->next;
                sortq = start->next;
                i *= 2;
                continue;
            }
            //merge 2 node;
            int ip = i;
            int iq = i;
            while (ip > 0 && iq > 0 && sortq != nullptr) {
                if (sortp->val < sortq->val) {
                    --ip;
                    sortStart->next = sortp;
                    sortp = sortp->next;
                    sortStart = sortStart->next;
                } else {
                    --iq;
                    sortStart->next = sortq;
                    sortq = sortq->next;
                    sortStart = sortStart->next;
                }
            }
            if (ip == 0) {
                while (iq > 0 && sortq != nullptr) {
                    sortStart->next = sortq;
                    sortq = sortq->next;
                    sortStart = sortStart->next;
                    --iq;
                }
            } else {
                while (ip > 0 && sortp != nullptr) {
                    sortStart->next = sortp;
                    sortp = sortp->next;
                    sortStart = sortStart->next;
                    --ip;
                }
            }
            sortp = sortq;
            sortStart->next = sortp;
            if (sortq == nullptr) {
                sortStart = start;
                sortp = start->next;
                sortq = start->next;
                i *= 2;
            }
        }
        return start->next;
    }
};

int main() {
    ListNode * head = new ListNode(4);
    ListNode *p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(3);
    Solution sol;
    head = sol.sortList(head);
    return 0;
}