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
    int trap(vector<int>& height) {
        stack<int> st;
        int n = height.size();
        int ansr = 0;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && height[st.top()] < height[i]) {
                int cur = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int l = st.top();
                int r = i;
                int h = min(height[r], height[l]) - height[cur];
                ansr += (r-l-1) * h;
            }
            st.push(i);
        }
        return ansr;
    }
};

int main() {
    return 0;
}