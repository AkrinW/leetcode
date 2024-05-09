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
    int getMaxNum(TreeNode *p) {
        int maxSum = -1001;
        int maxLine = -1001;
        if (p != nullptr) {
            int maxSumL = getMaxNum(p->left);
            int maxSumR = getMaxNum(p->right);
            int maxLineL = getmaxLine(p->left);
            int maxLineR = getmaxLine(p->right);
            maxSum = maxSumL > maxSumR ? maxSumL : maxSumR;
            maxLine = maxLineL > maxLineR ? maxLineL : maxLineR;
            if (p->val > 0) {
                maxLine += p->val;
            }
            maxLine = maxLine > maxLineL + p->val + maxLineR ? maxLine : maxLineL + p->val + maxLineR;
            maxLine = maxLine > p->val ? maxLine : p->val;
            maxSum = maxSum > maxLine ? maxSum : maxLine;
        }
        return maxSum;
    }
    int maxPathSum(TreeNode* root) {
        return getMaxNum(root);
    }

    int getmaxLine(TreeNode *p) {
        int maxLine = -1001;
        if (p != nullptr) {
            int maxLineL = getmaxLine(p->left);
            int maxLineR = getmaxLine(p->right);
            maxLine = maxLineL > maxLineR ? maxLineL : maxLineR;
            maxLine += p->val;
            maxLine = maxLine > p->val ? maxLine : p->val;
        }
        return maxLine;
    }
};

int main() {
    Solution solue;

    return 0;
}
