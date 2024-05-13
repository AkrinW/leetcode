#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        int left = 0;
        int right = 0;
        std::stack<int> st;
        std::vector<std::string> gen;
        std::string tmp = "";
        for (int i = 0; i < 2*n; ++i) {
            tmp += ' ';
        }
        st.push(0);
        ++left;
        int pos = left + right - 1;
        tmp[pos] = '(';
        while (!st.empty()) {
            if (left < n) {
                st.push(0);
                ++left;
                ++pos;
                tmp[pos] = '(';
            } else {
                while(right < left) {
                    st.push(1);
                    ++right;
                    ++pos;
                    tmp[pos] = ')';
                }
                gen.push_back(tmp);
                while (!st.empty() && (st.top() == 1 || (st.top() == 0 && left == right + 1))) {
                    if (st.top() == 0) {
                        --left;
                    } else {
                        --right;
                    }
                    --pos;
                    st.pop();
                }
                if (st.empty()){
                    break;
                }
                st.pop();
                --left;
                st.push(1);
                ++right;
                tmp[pos] = ')';
            }
        }
        return gen;
    }
};

int main() {
    int n = 3;
    Solution sol;
    std::vector<std::string> gen = sol.generateParenthesis(n);
    return 0;
}