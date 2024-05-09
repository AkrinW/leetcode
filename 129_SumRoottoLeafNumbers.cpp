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
    int sumNumbers(TreeNode* root) {
        TreeNode* tail = root;
        std::stack<TreeNode*> st1;
        std::stack<int> st2;
        int sum = 0;
        int tmp = 0;
        while (tail != nullptr) {
            tmp = tmp * 10 + tail->val;
            if (tail->left == nullptr && tail->right == nullptr) {
                sum += tmp;
                if (st1.empty()) {
                    break;
                }
                do {
                    tail = st1.top()->right;
                    tmp = st2.top();
                    st1.pop();
                    st2.pop();
                } while (!st1.empty() && tail == nullptr);
            } else if (tail->left == nullptr) {
                tail = tail->right;
            } else {
                st1.push(tail);
                st2.push(tmp);
                tail = tail->left;
            }
        }
        return sum;
    }
};