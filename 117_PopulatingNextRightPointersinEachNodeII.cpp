#include <iostream>
#include <stack>
#include <vector>
#include <queue>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        std::queue<Node*> q1,q2;
        if (root != nullptr) {
            q1.push(root);
            while (!(q1.empty() && q2.empty())) {
                Node *p;
                while (!q1.empty()) {
                    p = q1.front();
                    q1.pop();
                    if (!q1.empty()) {
                        p->next = q1.front();
                    }
                    if (p->left) {
                        q2.push(p->left);
                    }
                    if (p->right) {
                        q2.push(p->right);
                    }
                }
                while (!q2.empty()) {
                    p = q2.front();
                    q2.pop();
                    if (!q2.empty()) {
                        p->next = q2.front();
                    }
                    if (p->left) {
                        q1.push(p->left);
                    }
                    if (p->right) {
                        q1.push(p->right);
                    }
                }
            }
        }
        return root;
    }
};