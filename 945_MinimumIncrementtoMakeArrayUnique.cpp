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
    int minIncrementForUnique(vector<int>& nums) {
        std::unordered_map<int, int> map;
        int n = nums.size();
        int min = 0;
        sort(nums.begin(), nums.end());
        int minus = nums[0] - 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < minus + i) {
                min += minus + i - nums[i];
            } else if (nums[i] == minus + i) {
                continue;
            } else {
                minus = nums[i] - i;
            }
        }
        return min;
    }
};

int main() {
    return 0;
}