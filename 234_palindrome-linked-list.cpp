#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <array>
#include <cctype>
#include <functional>
#include <ranges>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//优化cin 和cout 速度
auto __FAST__IO__ = []() noexcept -> int {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    return 0;
}();

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *halfNode = head, *tmp = head;
        if (head->next == nullptr) {
            return true;
        }
        while (tmp != nullptr) {
            tmp = tmp->next;
            if (!tmp) {
                break;
            }
            tmp = tmp->next;
            if (!tmp) {
                break;
            }
            halfNode = halfNode->next;
        }
        tmp = halfNode->next;
        // 反转后半段
        while (tmp->next) {
            ListNode *q = tmp->next;
            tmp->next = q->next;
            q->next = halfNode->next;
            halfNode->next = q;
        }
        // 比较前后半段
        tmp = halfNode->next;
        halfNode = head;
        while (tmp) {
            if (tmp->val != halfNode->val) {
                return false;
            }
            tmp = tmp->next;
            halfNode = halfNode->next;
        }
        return true;
    }
};

int main() {
    return 0;
}