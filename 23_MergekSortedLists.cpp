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
private:
    // ListNode* merge2(ListNode *a, ListNode *b) {
    //     ListNode *start = new ListNode(0,a);
    //     ListNode *m = start;
    //     ListNode *p = a;
    //     ListNode *q = b;
    //     while (p != nullptr && q != nullptr) {
    //         if (p->val < q->val) {
    //             m->next = p;
    //             p = p->next;
    //             m = m->next;
    //         } else {
    //             m->next = q;
    //             q = q->next;
    //             m = m->next;
    //         }
    //     }
    //     if (p != nullptr) {
    //         m->next = p;
    //     } else {
    //         m->next = q;
    //     }
    //     return start->next;
    // }
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        int num = lists.size();
        if (num == 0) {
            return nullptr;
        }
        int i = 0;
        int c = 1;
        while (c < num) {
            if (i+c >= num) {
                c *= 2;
                i = 0;
                continue;
            }
            // lists[i] = merge2(lists[i],lists[i+c]);
            ListNode *start = new ListNode(0,lists[i]);
            ListNode *m = start;
            ListNode *p = lists[i];
            ListNode *q = lists[i+c];
            while (p != nullptr && q != nullptr) {
                if (p->val < q->val) {
                    m->next = p;
                    p = p->next;
                    m = m->next;
                } else {
                    m->next = q;
                    q = q->next;
                    m = m->next;
                }
            }
            if (p != nullptr) {
                m->next = p;
            } else {
                m->next = q;
            }
            lists[i] = start->next;
            i += 2*c;
        }
        return lists[0];
    }
};

int main() {

    return 0;
}