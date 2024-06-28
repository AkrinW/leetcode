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
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int num = roads.size();
        vector<int> cities(n, 0);
        for (int i = 0; i < num; ++i) {
            ++cities[roads[i][0]];
            ++cities[roads[i][1]];
        }
        sort(cities.begin(), cities.end());
        long long maxism = 0;
        for (int i = 0; i < n; ++i) {
            maxism += long(i+1) * long(cities[i]);
        }
        return maxism;
    }
};
int main() {
    return 0;
}