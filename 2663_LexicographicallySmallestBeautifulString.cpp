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
#include <ranges>
using namespace std;

//优化cin 和cout 速度
auto __FAST__IO__ = []() noexcept -> int {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    return 0;
}();

class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        int i = n - 1;
        std::stack<int> st;
        s[i] += 1;
        st.push(i);
        while (i != n && i != -1) {
            while (s[i] - 'a' < k) {
                if ((i < 1 || s[i-1] != s[i]) && (i < 2 || s[i-2] != s[i])) {
                    break;
                } else {
                    s[i] += 1;
                }
            }
            if (s[i] - 'a' == k) {
                if (i == 0) {
                    return "";
                } else {
                    s[i] = 'a';
                    --i;
                    s[i] += 1;
                }
            } else {
                ++i;
            }
        }
        return s;
        // while (!st.empty()) {
        //     int p = st.top();
        //     int trie = s[p] - 'a';
        //     char tmp;
        //     while (trie < k) {
        //         tmp = 'a' + trie;
        //         if ((p == 0 || s[p-1] != tmp) && (p < 2 || s[p-2] != tmp)) {
        //             break;
        //         } else {
        //             ++trie;
        //         }
        //     }
        //     if (trie == k) {
        //         if (p == 0) {
        //             return "";
        //         } else {
        //             s[p] = 'a';
        //             s[p-1] += 1;
        //             st.push(p-1);
        //         }
        //     } else {
        //         s[p] = tmp;
        //         st.pop();
        //     }
        // }
        // return s;
    }
};

int main() {
    Solution sol;
    sol.smallestBeautifulString("abcz", 26);
    return 0;
}