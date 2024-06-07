#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <array>
#include <cctype>
#include <functional>
using namespace std;

//优化cin 和cout 速度
auto __FAST__IO__ = []() noexcept -> int {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    return 0;
}();

class Solution {
private:
    struct Node {
        int endflag;
        std::vector<Node*> next;
        Node(): endflag(0), next(26,nullptr){}
    };
    Node *root;
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new Node();
        int n = dictionary.size();
        for (int i = 0; i < n; ++i) {
            int m = dictionary[i].size();
            Node *p = root;
            for (int j = 0; j < m; ++j) {
                int tmp = dictionary[i][j]-'a';
                if (p->next[tmp] == nullptr) {
                    p->next[tmp] = new Node();
                }
                p = p->next[tmp];
            }
            p->endflag = 1;
        }
        n = sentence.size();
        int i = 0;
        string replace = "";
        while (i < n) {
            if (sentence[i] == ' '){
                replace += ' ';
                ++i;
                continue;
            }
            int j = i;
            Node *p = root;
            bool flag = false;
            while (j < n && sentence[j] != ' ') {
                int tmp = sentence[j] - 'a';
                if (p->next[tmp] == nullptr) {
                    break;
                } else {
                    p = p->next[tmp];
                    ++j;
                    if (p->endflag == 1) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) {
                replace += sentence.substr(i, j-i);
                while (j < n && sentence[j] != ' ') {
                    ++j;
                }
            } else {
                while (j < n && sentence[j] != ' ') {
                    ++j;
                }
                replace += sentence.substr(i, j-i);
            }
            i = j;
        }
        return replace;
    }
};

int main() {
    Solution sol;
    vector<string> diction = {"a","aa","aaaa"};
    string sente = "aadsfasf absbs bbab cadsfafs";
    sol.replaceWords(diction, sente);
    return 0;
}