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
    long long maxScore(vector<int>& nums, int x) {
        long long dpmax1 = -1e8, dpmax2 = -1e8;//奇数偶数结尾
        if (nums[0] % 2 == 0) {
            dpmax2 = nums[0];
        } else {
            dpmax1 = nums[0];
        }
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] % 2 == 0) {
                dpmax2 = std::max(dpmax1 - x, dpmax2) + nums[i];
            } else {
                dpmax1 = std::max(dpmax1, dpmax2 - x) + nums[i];
            }
        }
        return std::max(dpmax1, dpmax2);
    }
};

int main() {
    return 0;
}