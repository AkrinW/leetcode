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
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        int max = 0;
        int n = nums.size();
        while (j < n) {
            if (nums[j] - nums[i] <= 2 * k) {
                ++j;
            } else {
                max = max > (j-i) ? max : (j-i);
                while (nums[j]- nums[i] > 2*k) {
                    ++i;
                }
            }
        }
        max = max > (j-i) ? max : j-i;
        return max;
    }
};

int main() {
    return 0;
}