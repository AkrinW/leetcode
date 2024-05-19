#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <array>
#include <cctype>

class Solution {
public:
    long long maximumValueSum(std::vector<int>& nums, int k, std::vector<std::vector<int>>& edges) {
        int n = nums.size();
        long long max = 0;
        if (k == 0) {
            for (int i = 0; i < n; ++i) {
                max += nums[i];
            }
            return max;
        }
        int count_xor = 0;
        int max_negative = -1e7;
        int min_positive = 1e7;
        for (int i = 0; i < n; ++i) {
            int tmp = nums[i] ^ k;
            if (tmp > nums[i]) {
                ++count_xor;
                min_positive = min_positive < (tmp-nums[i]) ? min_positive : (tmp-nums[i]);
                max += tmp;
            } else {
                max_negative = max_negative > (tmp-nums[i]) ? max_negative : (tmp-nums[i]);
                max += nums[i];
            }
        }
        if (count_xor % 2 == 1) {
            if (count_xor < n - 1 && min_positive + max_negative > 0) {
                max += max_negative;
            } else {
                max -= min_positive;
            }
        } 
        return max;
    }
};


int main() {
    return 0;
}