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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        TreeNode *p = root;
        std::stack<TreeNode*> st;
        while (p != nullptr || !st.empty()) {
            while (p != nullptr) {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            ++count;
            if (count == k) {
                return p->val;
            }
            p = p->right;
        }
        return -1;
    }  
};