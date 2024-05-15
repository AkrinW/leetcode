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
    bool isPalindrome(int x) {
        if (x < 0 || x % 10 == 0) {
            return false;
        }
        int p = 0;
        while (x > p) {
            p *= 10;
            p += x % 10;
            x /= 10;
        }
        if (x == p) {
            return true;
        } else {
            p /= 10;
            if (x == p) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}