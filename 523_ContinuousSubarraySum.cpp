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
    bool checkSubarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        map[0] = -1;
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        nums[0] = nums[0] % k;
        if (!map.count(nums[0])) {
            map[nums[0]] = 0;
        }
        for (int i = 1; i < n; ++i) {
            nums[i] = (nums[i-1] + nums[i]) % k;
            if (!map.count(nums[i])) {
                map[nums[i]] = i;
            } else {
                if (i - map[nums[i]] > 1) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    return 0;
}