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
    int maxDepth(TreeNode* root) {
        int max = 1;
        if (root == nullptr) {
            return 0;
        } else {
            int a = maxDepth(root->left);
            int b = maxDepth(root->right);
            max += a > b ? a : b;
            return max;
        }
    }
};