#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cstdint>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int n = nums.size();
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            b = ~a & (b ^ nums[i]);
            a = ~b & (a ^ nums[i]);
        }
        return b;
    }
};

int main() {
    return 0;
}