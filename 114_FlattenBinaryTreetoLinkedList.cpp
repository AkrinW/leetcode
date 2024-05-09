#include <iostream>
#include <stack>
#include <vector>

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
    void flatten(TreeNode* root) {
        TreeNode* tail = root;
        std::stack<TreeNode*> st;
        while (tail != nullptr) {
            TreeNode *p;
            if (tail->left == nullptr && tail->right == nullptr) {
                if (st.empty()) {
                    break;
                }
                p = st.top();
                tail->right = p->right;
                p->right = p->left;
                p->left = nullptr;
                st.pop();
            } else if (tail->left == nullptr) {
                tail = tail->right;
            } else {
                st.push(tail);
                tail = tail->left;
            }
        }
    }
};