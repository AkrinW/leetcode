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
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        std::deque<int> min, max;
        int left = 0, right = 0;
        int longest = 0;
        while (right < n) {
            while (!min.empty() && min.back() > nums[right]) {
                min.pop_back();
            }
            while (!max.empty() && max.back() < nums[right]) {
                max.pop_back();
            }
            min.push_back(nums[right]);
            max.push_back(nums[right]);
            while (!min.empty() && !max.empty() && max.front() - min.front() > limit) {
                if (min.front() == nums[left]) {
                    min.pop_front();
                }
                if (max.front() == nums[left]) {
                    max.pop_front();
                }
                ++left;
            }
            ++right;
            longest = longest > right - left ? longest : right - left;
        }
        return longest;
    }
};

int main() {
    return 0;
}