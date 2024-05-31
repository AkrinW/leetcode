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
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int a = 0;
        for (auto u : nums) {
            a ^= u;
        }  
        int bit = 1;
        while (a % 2 == 0) {
            bit <<= 1;
            a >>= 1;
        }
        a = 0;
        int b = 0;
        for (auto u : nums) {
            if ((bit & u) == 0) {
                a ^= u;
            } else {
                b ^= u;
            }
        }
        return std::vector<int>{a,b};
    }
};

int main() {
    std::vector<int> nums{1,2,1,3,2,5};
    Solution sol;
    sol.singleNumber(nums);
    return 0;
}