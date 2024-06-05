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
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> ch(26,INT_MAX);
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            vector<int> tmp(26,0);
            int nw = words[i].size();
            bool flag = true;
            for (int j = 0; j < nw;++j) {
                ++tmp[words[i][j]-'a'];
            }
            for (int j = 0; j < 26; ++j) {
                ch[j] = ch[j] < tmp[j] ? ch[j] : tmp[j];
                if (ch[j] > 0) {
                    flag = false;
                }
            }
            if (flag) {
                break;
            }
        }
        vector<string> s;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < ch[i]; ++j) {
                s.push_back(string(1,char('a'+i)));
            }
        }
        return s;
    }
};
int main() {
    return 0;
}