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
    long long minimumSteps(string s) {
        long long n = s.size();
        long long i = 0, j = n - 1;
        long long min = 0;
        while (i < j) {
            while (s[j] == '1' && j >= 0) {
                --j;
            }
            while (s[i] == '0' && i < n) {
                ++i;
            }
            if (i > j) {
                break;
            }
            min += long(j - i);
            --j;
            ++i;
        }
        return min;
    }
};

int main() {
    return 0;
}