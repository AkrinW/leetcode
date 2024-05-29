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
        int max = -1;
        for (int i = n-2; i > 0; --i) {
            unordered_map<string, int> map;
            for (int j = 0; j < 26; ++j) {
                string tmp(i,'a'+j);
                ++map[tmp];
            }
            for (int j = 0; j <= n-i; ++j) {
                string tmp = s.substr(j,i);
                if (map.count(tmp)) {
                    ++map[tmp];
                    if (map[tmp] == 4) {
                        max = i;
                        return max;
                    }
                }
            }
        }
        return max;
    }
};

int main() {
    return 0;
}