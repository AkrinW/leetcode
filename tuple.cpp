#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

struct TreeNode {
    vector<int> vals;
    set<TreeNode*> childs;
    TreeNode() {}
    TreeNode(string a) {
        int n = a.size();
        stack<TreeNode*> stk;
        auto cur = this;
        stk.push(cur);
        for (auto ch : a) {
            if (ch == '[') {
                TreeNode *p = new TreeNode();
                cur->childs.emplace(p);
                stk.push(p);
                cur = stk.top();
            } else if (ch == ',') {

            } else if (ch == ']') {
                stk.pop();
                cur = stk.top();
            } else {
                int tmp = ch-'0';
                cur->vals.push_back(tmp);
            }
        }
    }
};

bool compareTree(TreeNode *a, TreeNode *b) {
    int nva = a->vals.size();
    int nvb = b->vals.size();
    int nca = a->childs.size();
    int ncb = b->childs.size();
    if (nva != nvb || nca != ncb) {
        return false;
    }
    sort(a->vals.begin(),a->vals.end());
    sort(b->vals.begin(),b->vals.end());
    for (int i = 0; i < nva; ++i) {
        if(a->vals[i] != b->vals[i]) {
            return false;
        }
    }
    while (!a->childs.empty()) {
        bool flag = false;
        auto childa = *a->childs.begin();
        // 对于子节点，需要进行一一匹配，找到后移除相应的
        for (auto childb: b->childs) {
            if (compareTree(childa, childb)) {
                flag = true;
                b->childs.erase(childb);
                break;
            }
        }
        if (flag) {
            a->childs.erase(childa);
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<TreeNode*> t1(n);
    vector<TreeNode*> t2(n);
    for (int i = 0; i < n; ++i) {
        string a,b;
        cin >> a >> b;
        t1[i] = new TreeNode(a);
        t2[i] = new TreeNode(b);
    }
    for (int i = 0; i < n; ++i) {
        if (compareTree(t1[i],t2[i])) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }
    return 0;
}