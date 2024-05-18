#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        TreeNode *p = root;
        std::stack<TreeNode*> st;
        int distri = 0;
        TreeNode *lastvisit = nullptr;
        while (p != nullptr || !st.empty()) {
            while (p != nullptr) {
                st.push(p);
                p = p->left;
            }
            TreeNode *top = st.top();
            if (top->right && lastvisit != top->right) {
                p = top->right;
            } else {
                if (top->left != nullptr && top->left->val != 1) {
                    int tmp = 1 - top->left->val;
                    top->left->val = 1;
                    top->val -= tmp;
                    distri += abs(tmp);
                }
                if (top->right != nullptr && top->right->val != 1) {
                    int tmp = 1 - top->right->val;
                    top->right->val = 1;
                    top->val -= tmp;
                    distri += abs(tmp);
                }
                lastvisit = top;
                st.pop();
            }
        }
        return distri;
    }
};

int main() {
    return 0;
}