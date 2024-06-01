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
    int distributeCandies(int n, int limit) {
        int sum = 0;
        if (n > limit * 3 || n <= 0) {
            return 0;
        } else if (n > limit * 2) {
            int tmp = 3 * limit - n + 1;
            sum = (tmp + 1) * tmp / 2;
        } else if (n < limit) {
            int tmp = n + 1;
            sum = (tmp + 1) * tmp / 2;
        } else {
            sum = (limit + 1) * (limit + 1);
            int tmp = n - limit;
            sum -= (tmp+1)*tmp/2;
            tmp = 2 *limit - n;
            sum -= (tmp+1)*tmp/2;
        }
        return sum;
    }
};

int main() {
    return 0;
}