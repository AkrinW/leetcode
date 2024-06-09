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
    int subarraysDivByK(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        int n = nums.size();
        map[0] = 1;
        nums[0] %= k;
        if (nums[0] < 0) {
            nums[0] += k;
        }
        ++map[nums[0]];
        for (int i = 1; i < n; ++i) {
            nums[i] = (nums[i] + nums[i-1]) % k;
            if (nums[i] < 0) {
                nums[i] += k;
            }
            ++map[nums[i]];
        }
        int sub = 0;
        for (auto u : map) {
            sub += u.second*(u.second-1)/2;
        }   
        return sub;
    }
};

int main() {
    return 0;
}