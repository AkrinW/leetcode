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

//优化cin 和cout 速度
auto __FAST__IO__ = []() noexcept -> int {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    return 0;
}();

class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        int n = nums.size();
        auto f = [&](int i) -> int {
            int x = nums[i];
            if (i - 1 >= 0) {
                x += nums[i - 1];
            }
            if (i + 1 < n) {
                x += nums[i + 1];
            }
            return x;
        };

        int left = 0, right = -1;
        long long leftSum = 0, rightSum = 0;
        long long leftCount = 0, rightCount = 0;
        long long res = LONG_LONG_MAX;
        for (int i = 0; i < n; i++) {
            if (f(i) + maxChanges >= k) {
                if (k <= f(i)) {
                    res = min(res, (long long)k - nums[i]);
                } else {
                    res = min(res, (long long)2 * k - f(i) - nums[i]);
                }
            }
            if (k <= maxChanges) {
                continue;
            }
            while (right + 1 < n && (right - i < i - left || leftCount + rightCount + maxChanges < k)) {
                if (nums[right + 1] == 1) {
                    rightCount++;
                    rightSum += right + 1;
                }
                right++;
            }
            while (leftCount + rightCount + maxChanges > k) {
                if (right - i < i - left || right - i == i - left && nums[left] == 1) {
                    if (nums[left] == 1) {
                        leftCount--;
                        leftSum -= left;
                    }
                    left++;
                } else {
                    if (nums[right] == 1) {
                        rightCount--;
                        rightSum -= right;
                    }
                    right--;
                }
            }
            res = min(res, leftCount * i - leftSum + rightSum - rightCount * i + 2 * maxChanges);
            if (nums[i] == 1) {
                leftCount++;
                leftSum += i;
                rightCount--;
                rightSum -= i;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}