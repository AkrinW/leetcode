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
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        std::stack<TreeNode*> st;
        TreeNode *p = root;
        int prv;
        while (p != nullptr) {
            st.push(p);
            p = p->left;
        }
        p = st.top();
        st.pop();
        prv = p->val;
        p = p->right;
        while (p != nullptr || !st.empty()) {
            while (p != nullptr) {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            int now = p->val;
            if (prv >= now) {
                flag = false;
                return flag;
            }
            prv = now;
            p = p->right;
        }
        return flag;
    }
};