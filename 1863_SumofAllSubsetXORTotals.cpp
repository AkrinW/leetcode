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
    int subsetXORSum(std::vector<int>& nums) {
        int n = nums.size();
        int tmp = 0;
        for (int i = 0; i < n; ++i) {
            tmp |= nums[i];
        }
        return tmp * pow(2,n-1);
    }
};




int main() {
    return 0;
}