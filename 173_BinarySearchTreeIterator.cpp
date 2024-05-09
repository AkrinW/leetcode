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

class BSTIterator {
private:
    std::stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        TreeNode *p = root;
        while (p != nullptr) {
            st.push(p);
            p = p->left;
        }
    }
    
    int next() {
        TreeNode *p = st.top();
        int n = p->val;
        st.pop();
        if (p->right) {
            p = p->right;
            while (p != nullptr) {
                st.push(p);
                p = p->left;
            }
        }
        return n;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
};