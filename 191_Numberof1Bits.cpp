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
    int hammingWeight(int n) {
        int weight = 0;
        while(n != 0) {
            if (n & 1) {
                ++weight;
            }
            n >>= 1;
        }
        return weight;
    }
};

int main() {
    return 0;
}