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
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        // std::vector<int> inorder = {9,3,15,20,7};
    // std::vector<int> postorder = {9,15,7,20,3};
        int n = inorder.size();
        TreeNode *root;
        std::stack<TreeNode*> st;
        root = new TreeNode(postorder[n-1]);
        st.push(root);
        int i = n-1;
        int j = n-2;
        while (j >= -1) {
            TreeNode *p;
            if (inorder[i] != st.top()->val) {
                p = new TreeNode(postorder[j]);
            } else {
                TreeNode *q;
                while (!st.empty() && inorder[i] == st.top()->val) {
                    q = st.top();
                    st.pop();
                    if (!st.empty() && st.top()->right == nullptr) {
                        st.top()->right = q;
                    }
                    --i;
                }
                if (j > -1) {
                    p = new TreeNode(postorder[j]);
                } else {
                    break;
                }
                q->left = p;
            }
            st.push(p);
            --j;
        }
        return root;
    }
};

int main() {
    std::vector<int> inorder = {9,3,15,20,7};
    std::vector<int> postorder = {9,15,7,20,3};
    Solution solution;
    TreeNode *root = solution.buildTree(inorder, postorder);

    return 0;
}