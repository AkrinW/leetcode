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
    int numSquares(int n) {
        int square[101];
        for (int i = 1; i < 101; ++i) {
            square[i] = i * i;
        }
        int *dp = new int[n+1];
        dp[0] = 0;
        for (int i = 1; i < n+1; ++i) {
            dp[i] = dp[i-1] + 1;
            for (int j = 2; j < 101; ++j) {
                if (square[j] <= i) {
                    dp[i] = dp[i-square[j]] + 1 < dp[i] ? dp[i-square[j]] + 1 : dp[i];
                } else {
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    return 0;
}