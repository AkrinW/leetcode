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
    vector<int> distributeCandies(int candies, int n) {
        int m = (sqrt(8.0 * candies + 1) - 1) / 2;
        int k = m / n, extra = m % n;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = k * (k - 1) / 2 * n + k * (i + 1) + (i < extra ? k * n + i + 1 : 0);
        }
        ans[extra] += candies - m * (m + 1) / 2;
        return ans;
    }
};

int main() {
    return 0;
}