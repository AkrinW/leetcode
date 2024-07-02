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
    int maximumPrimeDifference(vector<int>& nums) {
        int p[101] = {0,0,1,1,0,1,0,1,0,0,0,
                        1,0,1,0,0,0,1,0,1,0,
                        0,0,1,0,0,0,0,0,1,0,
                        1,0,0,0,0,0,1,0,0,0,
                        1,0,1,0,0,0,1,0,0,0,
                        0,0,1,0,0,0,0,0,1,0,
                        1,0,0,0,0,0,1,0,0,0,
                        1,0,1,0,0,0,0,0,1,0,
                        0,0,1,0,0,0,0,0,1,0,
                        0,0,0,0,0,0,1,0,0,0};
        int i = 0, j = nums.size() - 1;
        while (p[nums[i]] == 0) {
            ++i;
        }
        while (p[nums[j]] == 0) {
            --j;
        }
        return j-i;
    }
};

int main() {
    return 0;
}