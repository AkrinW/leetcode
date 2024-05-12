#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
private:
    struct Node {
        int n;
        int sub;
        Node(){}
        Node(int _n, int _s){
            n = _n;
            sub = _s;
        }
    };
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        int num = digits.size();
        std::vector<std::string> let;
        if (num == 0) {
            return let;
        }
        std::stack<Node> st;
        std::vector<std::vector<char>> dig = {{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        int i = 0;
        int n = int(digits[i]-'0');
        Node p;
        st.push(Node(n,0));
        std::string s;
        for (int j = 0; j < num; ++j) {
            s += ' ';
        }
        while (!st.empty()) {
            p = st.top();
            if (p.sub < 3 || (p.sub == 3 && p.n == 7)|| (p.sub == 3 && p.n == 9)) {
                s[i] = dig[p.n][p.sub];
                ++i;
                if (i == num) {
                    let.push_back(s);
                    --i;
                    ++p.sub;
                    st.pop();
                    st.push(p);
                } else {
                    int tmp = int(digits[i]-'0');
                    st.push(Node(tmp,0));
                }
            } else {
                st.pop();
                if (st.empty()) {
                    break;
                }
                --i;
                p = st.top();
                ++p.sub;
                st.pop();
                st.push(p);
            }

        }
        return let;
    }
};

int main() {
    std::string digits = "23";
    Solution sol;
    std::vector<std::string> letter;
    letter = sol.letterCombinations(digits);

    return 0;
}