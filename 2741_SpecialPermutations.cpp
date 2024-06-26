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
    static const int mod = 1e9 + 7;
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> f(1 << n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            f[1 << i][i] = 1;
        }
        for (int state = 1; state < (1 << n); state++) {
            for (int i = 0; i < n; i++) {
                if (!(state >> i & 1)) {
                    continue;
                }
                for (int j = 0; j < n; j++) {
                    if (i == j || !(state >> j & 1)) {
                        continue;
                    }
                    if (nums[i] % nums[j] != 0 && nums[j] % nums[i] != 0) {
                        continue;
                    }
                    f[state][i] = (f[state][i] + f[state ^ (1 << i)][j]) % mod;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + f[(1 << n) - 1][i]) % mod;
        }
        return res;
    }
};

int main() {
    return 0;
}