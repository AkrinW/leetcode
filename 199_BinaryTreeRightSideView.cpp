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
    std::vector<int> rightSideView(TreeNode* root) {
        std::queue<TreeNode*> que1, que2;
        std::vector<int> output;
        if (root != nullptr) {
            que1.push(root);
            while (!que1.empty()) {
                output.push_back(que1.front()->val);
                while (!que1.empty()) {
                    TreeNode *p = que1.front();
                    if (p->right) {
                        que2.push(p->right);
                    }
                    if (p->left) {
                        que2.push(p->left);
                    }
                    que1.pop();
                }
                if (!que2.empty()) {
                    output.push_back(que2.front()->val);
                    while (!que2.empty()) {
                        TreeNode *p = que2.front();
                        if (p->right) {
                            que1.push(p->right);
                        }
                        if (p->left) {
                            que1.push(p->left);
                        }
                        que2.pop();
                    }
                }
            }
        }
        return output;
    }   
};