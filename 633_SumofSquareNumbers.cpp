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
    bool judgeSquareSum(int c) {
        long _c = c;
        long j = sqrt(_c);
        long i = 0;
        long long tmp;
        while (i <= j) {
            tmp = i * i + j * j;
            if (tmp < _c) {
                ++i;
            } else if (tmp > _c) {
                --j;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}