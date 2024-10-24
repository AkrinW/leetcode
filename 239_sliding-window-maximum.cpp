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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxlide(n-k+1);
        deque<int> que;
        for (int i = 0; i < k; ++i) {
            while (!que.empty() && nums[que.back()] <= nums[i]) {
                que.pop_back();
            }
            que.push_back(i);
        }
        maxlide[0] = nums[que.front()];
        for (int i = 0; i < n - k; ++i) {
            if (que.front() == i) {
                que.pop_front();
            }
            while(!que.empty() && nums[que.back()] <= nums[i+k]) {
                que.pop_back();
            }
            que.push_back(i+k);
            maxlide[i+1] = nums[que.front()];
        }
        return maxlide;
    }
};


int main() {
    return 0;
}