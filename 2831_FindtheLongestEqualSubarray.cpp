#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <array>
#include <cctype>
#include <functional>

class Solution {
public:
    int longestEqualSubarray(std::vector<int>& nums, int k) {
        int n = nums.size();
        int max = 0;
        std::unordered_map<int, int> map;
        int start = nums[0];
        int end = nums[0];
        for (int i = 0, j = 0; j < n; ++j) {
            end = nums[j];
            ++map[end];
            while(j-i+1-map[start]>k) {
                --map[start];
                ++i;
                start = nums[i];
            }
            max = max > map[end] ? max : map[end];
        }
        return max;
    }
};

int main() {
    return 0;
}