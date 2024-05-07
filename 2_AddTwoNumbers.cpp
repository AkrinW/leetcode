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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0,nullptr);
        ListNode* p = head;
        int carry = 0;
        while (l1 || l2 || carry) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            p->val = n1 + n2 + carry;
            if (p->val > 9) {
                p->val = p->val - 10;
                carry = 1;
            } else {carry = 0;}
            if (l1) {l1 = l1->next;}
            if (l2) {l2 = l2->next;}
            if (l1 || l2 || carry) {
                p->next = new ListNode(0,nullptr);
            }
            p = p->next;
        }
        return head;
    }
};