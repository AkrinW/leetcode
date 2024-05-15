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
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverse = 0;
        for (int i = 0; i < 32; ++i) {
            uint32_t tmp = n&1;
            reverse += tmp;
            reverse <<= 1;
            n >>= 1;
        }
        return reverse;
    }
};

int main() {
    Solution sol;
    sol.reverseBits(3);
    return 0;
}