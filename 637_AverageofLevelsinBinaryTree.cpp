#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <unordered_map>
#include <iomanip>

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
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::queue<TreeNode*> que1, que2;
        std::vector<double> avr;
        if (root != nullptr) {
            que1.push(root);
            while (!que1.empty()) {
                int count = 0;
                double average = 0;
                while (!que1.empty()) {
                    TreeNode *p = que1.front();
                    if (p->left) {
                        que2.push(p->left);
                    }
                    if (p->right) {
                        que2.push(p->right);
                    }                
                    average += p->val;
                    ++count;
                    que1.pop();
                }
                average /= count;
                avr.push_back(average);
                average = 0;
                count = 0;
                while (!que2.empty()) {
                    TreeNode *p = que2.front();
                    if (p->left) {
                        que1.push(p->left);
                    }
                    if (p->right) {
                        que1.push(p->right);
                    }
                    average += p->val;
                    ++count;
                    que2.pop();
                }
                if (count) {
                    average /= count;
                    avr.push_back(average);
                }
            }
        }
        return avr;
    }
};
