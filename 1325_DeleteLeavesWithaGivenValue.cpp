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
private:
    bool removeNodes(TreeNode* &p, int target) {
        if (p == nullptr) {
            return true;
        }
        bool flag1 = removeNodes(p->left, target);
        bool flag2 = removeNodes(p->right,target);
        if (flag1) {
            p->left = nullptr;
        }
        if (flag2) {
            p->right = nullptr;
        }
        if (flag1 && flag2) {
            if (p->val == target) {
                delete p;
                p = nullptr;
                return true;
            }
        }
        // } else if (flag1) {
        //     p->left = nullptr;
        // } else if (flag2) {
        //     p->right = nullptr;
        // }
        return false;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // bool flag = removeNodes(root,target);
        // return root;
        std::stack<TreeNode*> st;
        TreeNode *cur = root;
        TreeNode *lastvisit = nullptr;
        while (cur != nullptr || !st.empty()) {
            while (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode *top = st.top();
            if (top->right && lastvisit != top->right) {
                cur = top->right;
            } else {
                if (top->left != nullptr && top->left->val == -1) {
                        delete top->left;
                        top->left = nullptr;
                }
                if (top->right != nullptr && top->right->val == -1) {
                        delete top->right;
                        top->right = nullptr;
                    }
                if (top->val == target && top->left == nullptr && top->right == nullptr) {
                    top->val = -1;
                }
                lastvisit = top;
                st.pop();
            }
        }
        if (root->val == -1) {
            root = nullptr;
        }
        return root;
        // st.push(root);
        // TreeNode *lastvisit = nullptr;
        // TreeNode *p = root;
        // return p;
        // 递归
        
    }
};

int main() {
    TreeNode *p = new TreeNode(1);
    TreeNode *q = new TreeNode(1);
    TreeNode *r = new TreeNode(1);
    p->left = q;
    p->right = r;
    Solution sol;
    TreeNode * s = sol.removeLeafNodes(p,1);
    return 0;
}