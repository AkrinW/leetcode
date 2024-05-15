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
    int trailingZeroes(int n) {
        int zeros = 0;
        while(n > 4) {
            zeros += n/5;
            n /= 5;
        }
        return zeros;
    }
};

int main() {
    return 0;
}