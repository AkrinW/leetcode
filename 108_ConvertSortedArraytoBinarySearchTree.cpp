#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    std::vector<int> num;
    TreeNode* sort(int i, int j) {
        if (i > j) {
            return nullptr;
        }
        int k = (i+j)/2;
        TreeNode *r = new TreeNode(num[k]);
        r->left = sort(i, k-1);
        r->right = sort(k+1,j);
        return r;
    }
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        int n = nums.size();
        num = nums;
        TreeNode *p;
        p = sort(0,n-1);
        return p;
    }
};

int main() {
    std::vector<int> nums = {-10,-3,0,5,9};
    Solution sol;
    TreeNode *p = sol.sortedArrayToBST(nums);
    return 0;
}