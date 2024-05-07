/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *merge, *merge2;
        if (list1 == nullptr) {return list2;}
        if (list2 == nullptr) {return list1;}
        if (list1->val < list2->val) {
            merge = list1;
            merge2 = list2;
        } else {
            merge = list2;
            merge2 = list1;
        }
        ListNode *p = merge;
        while(merge2) {
            if(p->next == nullptr) {
                p->next = merge2;
                return merge;
            } else {
                if(p->next->val < merge2->val) {
                    p = p->next;
                } else {
                    ListNode *tmp = p->next;
                    p->next = merge2;
                    merge2 = tmp;
                    p = p->next;
                }
            }
        }
        return merge;
    }
};