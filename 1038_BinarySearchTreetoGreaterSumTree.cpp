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
    TreeNode* bstToGst(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        std::stack<TreeNode*> st;
        TreeNode* p = root;
        // st.push(p);
        int cursum = 0;
        while (!st.empty() || p != nullptr) {
            while (p != nullptr) {
                st.push(p);
                p = p->right;
            }
            p = st.top();
            cursum += p->val;
            p->val = cursum;
            st.pop();
            p = p->left;
        }
        return root;
    }
};

int main() {
    return 0;
}