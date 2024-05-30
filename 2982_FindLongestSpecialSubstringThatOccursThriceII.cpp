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
    int maximumLength(string s) {
        int n = s.size();
        int max = 0;
        std::vector<std::vector<int>> table(26,std::vector<int>(3,0));
        int i = 0;
        while (i < n) {
            int index = s[i] - 'a';
            int j = i;
            while (j < n && s[j] == s[i]) {
                ++j;
            }
            int len = j - i;
            if (len > table[index][0]) {
                table[index][2] = table[index][1];
                table[index][1] = table[index][0];
                table[index][0] = len;
            } else if (len > table[index][1]) {
                table[index][2] = table[index][1];
                table[index][1] = len;
            } else if (len > table[index][2]) {
                table[index][2] = len;
            }
            i = j;
        }
        for (int i = 0; i < 26; ++i) {
            int len;
            if (table[i][1] < table[i][0] - 1) {
                len = table[i][0] - 2;
            } else if (table[i][2] < table[i][0]) {
                len = table[i][0] - 1;
            } else {
                len = table[i][0];
            }
            max = max > len ? max : len;
        }
        if (max == 0) {
            return -1;
        }
        return max;
    }
};

int main() {
    return 0;
}