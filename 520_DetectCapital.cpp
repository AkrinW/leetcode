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
    bool detectCapitalUse(string word) {
        int n = word.size();
        bool flag = true;
        if (n == 1) {
            return flag;
        }
        if (word[0] >= 'a' && word[0] <= 'z') {
            for (int i = 1; i < n; ++i) {
                if (word[i] >= 'A' && word[i] <= 'Z') {
                    flag = false;
                    break;
                }
            }
        } else {
            int i = 2;
            bool prestr = true;
            if (word[1] >= 'a' && word[1] <= 'z') {
                prestr = false;
            }
            while (i < n) {
                bool tmp = true;
                if (word[i] >= 'a' && word[i] <= 'z') {
                    tmp = false;
                }
                if (prestr != tmp) {
                    flag = false;
                    break;
                }
                prestr = tmp;
                ++i;
            }
        }
        return flag;
    }
};

int main() {
    return 0;
}