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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            ++map[nums[i]];
        }
        auto cmp_greater = [](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int, int>>, decltype(cmp_greater)> que(cmp_greater);
        int count = 0;
        for (auto m: map) {
            if (count < k) {
                ++count;
                que.push(m);
            } else {
                if (cmp_greater(m,que.top())) {
                    que.pop();
                    que.push(m);
                }
            }
        }
        vector<int> topk;
        while (!que.empty()) {
            topk.push_back(que.top().first);
            que.pop();
        }
        return topk;
    }
};

int main() {
    Solution sol;
    vector<int> p = {5,2,5,3,5,3,1,1,3};
    sol.topKFrequent(p,2);
    return 0;
}