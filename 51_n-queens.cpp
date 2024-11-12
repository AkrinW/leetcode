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
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solves{};
        vector<int> col(n);
        vector<int> horizon(n), diagonal1(2*n-1), diagonal2(2*n-1);
        function<void(int)> dfs = [&](int r) {
            if (r == n) {
                vector<string> tmp(n);
                for (int i = 0; i < n; ++i) {
                    tmp[i] = (string(col[i],'.') + 'Q' + string(n-col[i]-1, '.'));
                }
                solves.push_back(tmp);
                return;
            }
            for (int i = 0; i < n; ++i) {
                if (!horizon[i] && !diagonal1[i+r] && !diagonal2[i-r+n-1]) {
                    col[r] = i;
                    horizon[i] = 1;
                    diagonal1[i+r] = 1;
                    diagonal2[i-r+n-1] = 1;
                    dfs(r+1);
                    horizon[i] = 0;
                    diagonal1[i+r] = 0;
                    diagonal2[i-r+n-1] = 0;
                }
            }
        };
        dfs(0);
        return solves;
    }
};

int main() {
    return 0;
}