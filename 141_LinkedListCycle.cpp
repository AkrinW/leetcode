#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main() {
    ListNode *head = new ListNode(2);
    int pos = 1;
    ListNode *fast = head, *slow = head;
    bool flag = true;
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
            if (fast == slow) {
                return flag;
            }
        }
    }
    flag = false;
    return 0;
}