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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::stack<TreeNode*> st1, st2;
        std::vector<std::vector<int>> output;
        if (root != nullptr) {
            st1.push(root);
            while (!st1.empty()) {
                std::vector<int> tmp;
                while (!st1.empty()) {
                    TreeNode *p = st1.top();
                    if (p->left) {
                        st2.push(p->left);
                    }
                    if (p->right) {
                        st2.push(p->right);
                    }
                    tmp.push_back(p->val);
                    st1.pop();
                }
                output.push_back(tmp);
                if (!st2.empty()) {
                    std::vector<int> tmp;
                    while (!st2.empty()) {
                        TreeNode *p = st2.top();
                        if (p->right) {
                            st1.push(p->right);
                        }
                        if (p->left) {
                            st1.push(p->left);
                        }
                        tmp.push_back(p->val);
                        st2.pop();
                    }
                    output.push_back(tmp);
                }
            }
        }   
        return output;
    }
};