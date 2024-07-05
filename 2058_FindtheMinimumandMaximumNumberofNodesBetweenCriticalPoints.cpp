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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        std::vector<int> node;
        int count = 0;
        int left = -1;
        int last = -1;
        int curr = -1;
        int flag = -1;
        int min = INT32_MAX;
        while (head->next != nullptr) {
            if (head->val == head->next->val) {
                flag = 2;
            } else if (head->val > head->next->val) {
                if (flag == 1) {
                    if (left == -1) {
                        left = count;
                    }
                    last = curr;
                    curr = count;
                    if (last != -1) {
                        min = min < curr-last ? min : curr -last;
                    }
                }
                flag = 0;
            } else {
                if (flag == 0) {
                    if (left == -1) {
                        left = count;
                    }
                    last = curr;
                    curr = count;
                    if (last != -1) {
                        min = min < curr - last ? min : curr - last;
                    }
                }
                flag = 1;
            }
            ++count;
        }
        if (last == -1) {
            node.push_back(-1);
            node.push_back(-1);
        } else {
            int max = curr -left;
            node.push_back(max);
            node.push_back(min);
        }
        return node;
    }
};

int main() {
    return 0;
}