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
    int minPatches(vector<int>& nums, int n) {
        //基本上是dp的思路，对于nums[i],需要记录当前能构造出的最大数字m(1,m)，
        // 如果m < nums[i] - 1，就需要补充一个数m+1,重新计算最大数字m。
        int count = 0;
        int len = nums.size();
        long long max = 0;
        int i = 0;
        while (max < n) {
            if (i < len && max < nums[i] - 1) {
                max += max + 1;
                ++count;
            } else if (i < len && max >= nums[i] - 1) {
                max += nums[i];
            } else {
                max += max + 1;
                ++count;
            }
        }
        return count;
    }
};

int main() {
    return 0;
}