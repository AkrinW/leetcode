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
    int numSteps(string s) {
        int n = s.size();
        bool flag = false;
        int count = 0;
        for (int i = n-1; i > 0; --i) {
            if (flag && s[i] == '0') {
                ++count;
            } else if (!flag && s[i] == '1') {
                flag = true;
            }
        }
        if (flag) {
            return n+1+count;
        }
        return n-1;
    }
};