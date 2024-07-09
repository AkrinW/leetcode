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
    int remove(vector<pair<int, int>> &arr, int i) {
        int n = arr.size();
        if (arr[0].second == i) {
            return arr[n - 1].first - arr[1].first;
        } else if (arr.back().second == i) {
            return arr[n - 2].first - arr[0].first;
        } else {
            return arr[n - 1].first - arr[0].first;
        }
    }
    
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, int>> sx, sy;
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            sx.emplace_back(x - y, i);
            sy.emplace_back(x + y, i);
        }
        sort(sx.begin(), sx.end());
        sort(sy.begin(), sy.end());
        int maxVal1 = sx.back().first - sx[0].first;
        int maxVal2 = sy.back().first - sy[0].first;
        int res = INT_MAX;
        if (maxVal1 >= maxVal2) {
            int i = sx[0].second, j = sx.back().second;
            // 去掉 i 后的最大曼哈顿距离
            res = min(res, max(remove(sx, i), remove(sy, i)));
            // 去掉 j 后的最大曼哈顿距离
            res = min(res, max(remove(sx, j), remove(sy, j)));
        } else {
            int i = sy[0].second, j = sy.back().second;
            // 去掉 i 后的最大曼哈顿距离
            res = min(res, max(remove(sx, i), remove(sy, i)));
            // 去掉 j 后的最大曼哈顿距离
            res = min(res, max(remove(sx, j), remove(sy, j)));
        }
        
        return res;
    }
};


int main() {
    return 0;
}