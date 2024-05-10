#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

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
    int getMinimumDifference(TreeNode* root) {
        int min = 1e6;
        int a = 0;
        int b = -1e6;
        TreeNode *p = root;
        std::stack<TreeNode*> st;
        while (p != nullptr || !st.empty()) {
            while (p != nullptr) {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            a = p->val;
            min = min < a - b ? min : a - b;
            if (min == 1) {
                return min;
            }
            b = a;
            p = p->right;
        }
        return min;
    }
};