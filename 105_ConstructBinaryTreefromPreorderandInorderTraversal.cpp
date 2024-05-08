#include <iostream>
#include <vector>
#include <stack>

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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        int n = preorder.size();
        TreeNode *root;
        std::stack<TreeNode*> st;
        root = new TreeNode(preorder[0]);
        st.push(root);
        int index = 0;
        int j = 1;
        while (j <= n) {
            TreeNode *p;
            if (inorder[index] == st.top()->val) {
                TreeNode *q;
                while (!st.empty() && inorder[index] == st.top()->val) {
                    q = st.top();
                    st.pop();
                    if (!st.empty() &&st.top()->left == nullptr) {
                        st.top()->left = q;
                    }
                    ++index;
                }
                if (j < n) {
                    p = new TreeNode(preorder[j]);
                } else {
                    break;
                }
                q->right = p;
            } else {
                p = new TreeNode(preorder[j]);
            }
            st.push(p);
            ++j;
        }
        return root;
    }
};

int main() {
    std::vector<int> preorder = {1,2};
    std::vector<int> inorder = {2,1};
    Solution solution;
    TreeNode *root = solution.buildTree(preorder, inorder);

    return 0;
}