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
        int t = nums[0];
        //异或两次，变回自身
        for (int i = 1; i < n; ++i) {
            t = t ^ nums[i];
        }
        return t;
    }
};

int main() {

    return 0;
}