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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> que;
        std::vector<std::vector<int>> output;
        int count = 0;
        if (root != nullptr) {
            que.push(root);
            ++count;
            while (count) {
                std::vector<int> tmp;
                int next = 0;
                while (count) {
                    TreeNode *p = que.front();
                    if (p->left) {
                        que.push(p->left);
                        ++next;
                    }
                    if (p->right) {
                        que.push(p->right);
                        ++next;
                    }
                    tmp.push_back(p->val);
                    que.pop();
                    --count;
                }
                count = next;
                output.push_back(tmp);
            }
        }   
        return output;
    }
};