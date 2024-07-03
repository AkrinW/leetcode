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
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int m[101] = {
            -1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1,
               -1, 3,-1,-1,-1,-1,-1, 9,-1, 2,
                3,-1,-1, 6,-1,-1, 9,-1,-1, 3,
               -1,-1,-1,-1,-1, 9,-1,-1,-1, 4,
               -1, 6,-1,-1, 9,-1,-1,12,-1, 5,
               -1,-1,-1, 9,-1,-1,-1,-1,-1, 6,
               -1,-1, 9,-1,-1,-1,-1,-1,-1, 7,
               -1, 9,-1,-1,-1,-1,-1,-1,-1, 8,
                9,-1,-1,12,-1,-1,-1,-1,-1, 9,
                -1,-1,-1,-1,-1,-1,-1,-1,-1,1
        };
        return m[x];
    }
};

int main() {
    return 0;
}