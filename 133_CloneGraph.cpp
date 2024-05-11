#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        std::stack<Node*> st;
        std::unordered_map<int, Node*> map;
        Node* p = node;
        if (p != nullptr) {
            st.push(p);
            while (!st.empty()) {
                p = st.top();
                st.pop();
                int a = p->val;
                if (!map.count(a)) {
                    Node *q = new Node(a);
                    map[a] = q;
                }
                std::vector<Node*> copy = p->neighbors;
                int num = copy.size();
                std::vector<Node*> tmp;
                for (int i = 0; i < num; ++i) {
                    int v = copy[i]->val;
                    if (!map.count(v)) {
                        Node *neigb = new Node(v);
                        map[v] = neigb;
                        st.push(copy[i]);
                    }
                    tmp.push_back(map[v]);
                }
                map[a]->neighbors = tmp;
            }
        } else {
            return nullptr;
        }
        return map[node->val];
    }
};