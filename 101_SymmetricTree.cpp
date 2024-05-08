#include <iostream>

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
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root->left,root->right);   
    }

    bool isSymmetric(TreeNode* p, TreeNode* q) {
        bool flag = true;
        if (p == nullptr && q == nullptr) {
            return flag;
        } else if (p != nullptr && q != nullptr) {
            if (p->val != q->val) {
                return false;
            }
            flag = isSymmetric(p->left,q->right) && isSymmetric(p->right,q->left);
        } else {
            return false;
        }
        return flag;
    }
};