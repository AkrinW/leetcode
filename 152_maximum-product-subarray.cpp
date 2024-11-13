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
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> max(n,1);
        vector<int> min(n,1);
        int maxproduct = -1e6;
        max[0] = nums[0];
        min[0] = nums[0];
        maxproduct = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] == 0) {
                max[i] = 0;
                min[i] = 0;
            } else if (nums[i] > 0) {
                max[i] = nums[i] > nums[i] * max[i-1] ? nums[i] : nums[i] * max[i-1];
                min[i] = nums[i] < nums[i] * min[i-1] ? nums[i] : nums[i] * min[i-1];
            } else {
                max[i] = nums[i] > nums[i] * min[i-1] ? nums[i] : nums[i] * min[i-1];
                min[i] = nums[i] < nums[i] * max[i-1] ? nums[i] : nums[i] * max[i-1];
            }
            maxproduct = maxproduct > max[i] ? maxproduct : max[i];
        }


        return maxproduct;
    }
};

int main() {
    return 0;
}