#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>

class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 2;
        if (n == 1) {
            return a;
        } else if (n == 2) {
            return b;
        }
        for (int i = 3; i <= n; ++i) {
            int tmp = b;
            b += a;
            a = tmp;
        }
        return b;
    }
};

int main() {
    return 0;
}