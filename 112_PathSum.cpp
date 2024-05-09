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
    bool hasPathSum(TreeNode* root, int targetSum) {
        TreeNode* tail = root;
        std::stack<TreeNode*> st1;
        std::stack<int> st2;
        bool flag = false;
        int target = targetSum;
        while (tail != nullptr) {
            target -= tail->val;
            if (tail->left == nullptr && tail->right == nullptr) {
                if (target == 0) {
                    return true;
                }
                if (st1.empty()) {
                    break;
                }
                do {
                    tail = st1.top()->right;
                    target = st2.top();
                    st1.pop();
                    st2.pop();
                } while (tail == nullptr && !st1.empty());
            } else if (tail->left == nullptr) {
                tail = tail->right;
            } else {
                st1.push(tail);
                st2.push(target);
                tail = tail->left;
            }
        }
        return flag;
    }
};