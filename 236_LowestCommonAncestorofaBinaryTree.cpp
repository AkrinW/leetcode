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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::unordered_map<TreeNode*, std::string> map;
        std::queue<TreeNode*> que;
        que.push(root);
        map[root] = "1";
        while (!que.empty()) {
            TreeNode *tmp = que.front();
            if (tmp->left != nullptr) {
                map[tmp->left] = map[tmp] + "0";
                que.push(tmp->left);
            }
            if (tmp->right != nullptr) {
                map[tmp->right] = map[tmp] + "1";
                que.push(tmp->right);
            }
            que.pop();
            if (map.count(p) && map.count(q)) {
                break;
            }
        }
        std::string subp = map[p];
        std::string subq = map[q];
        std::string low = "";
        TreeNode *lNode = root;
        for (int i = 1; i < subp.size(); ++i) {
            if (subp[i] != subq[i]) {
                break;
            }
            if (subp[i] == '0') {
                lNode = lNode->left;
            } else {
                lNode = lNode->right;
            }
        }
        return lNode;
    }
};

int main() {
    // [3,5,1,6,2,0,8,null,null,7,4];
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    Solution solut;
    TreeNode *p = solut.lowestCommonAncestor(root, root->left, root->right);
    return 0;
}