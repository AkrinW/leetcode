#include <iostream>
#include <stack>
#include <vector>
#include <queue>

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
    int countNodes(TreeNode* root) {
        std::queue<TreeNode*> q;
        int count = 0;
        if (root != nullptr) {
            q.push(root);
            while (!q.empty()) {
                TreeNode *p = q.front();
                ++count;
                q.pop();
                if (p->left == nullptr) {
                    count = count * 2 - 1;
                    break;
                }
                q.push(p->left);
                if (p->right == nullptr) {
                    count = count * 2;
                    break;
                }
                q.push(p->right);
            }
        }
        return count;
    }
};