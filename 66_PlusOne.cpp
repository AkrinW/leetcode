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
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size() - 1;
        bool flag = true;
        while (flag && n >= 0) {
            digits[n] = (digits[n] + 1) % 10;
            if (digits[n] != 0) {
                flag = false;
            }
            --n;
        }
        if (flag) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};


int main() {
    return 0;
}