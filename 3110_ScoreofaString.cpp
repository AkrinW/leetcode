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
    int scoreOfString(string s) {
        int sum = 0;
        int n = s.size();
        for (int i = 0; i < n-1; ++i) {
            if (s[i] < s[i+1]) {
                sum += s[i+1] - s[i];
            } else {
                sum += s[i] - s[i+1];
            }
        }
        return sum;
    }
};

int main() {
    return 0;
}