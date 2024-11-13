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
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int target = 0;
        for (int i = 0; i < n; ++i) {
            target += nums[i];
        }
        if (target % 2 == 1 || target < 2 * nums[n-1]) {
            return false;
        }
        target = target / 2 - nums[n-1];
        unordered_set<int> set;
        set.emplace(0);
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > target) {
                break;
            }
            vector<int> tmp;
            for (auto s: set) {
                if (!set.count(s+nums[i])) {
                    tmp.push_back(s+nums[i]);
                }
            }
            for (auto t: tmp) {
                set.emplace(t);
            }
        }
        if (set.count(target)) {
            return true;
        }
        return false;
    }
};

int main() {
    return 0;
}