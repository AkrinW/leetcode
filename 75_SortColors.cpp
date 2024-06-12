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
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, k = 0;
        while (k <= j) {
            if (nums[k] == 0 && k > i) {
                nums[k] = nums[i];
                nums[i] = 0;
                ++i;
            } else if (nums[k] == 2) {
                nums[k] = nums[j];
                nums[j] = 2;
                --j;
            } else {
                ++k;
            }
        }
    }
};

int main() {
    return 0;
}