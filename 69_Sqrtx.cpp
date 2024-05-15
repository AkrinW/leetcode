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
    int mySqrt(int x) {
        int my;
        if (x >= 2147395600) {
            return 46340;
        }
        if (x > 92681) {
            my = 46340;
            while (my * my > x) {
                my = my / 2 + x / (2 * my);
            }
            if ((my +1 )*(my +1) < x) {
                ++my;
            }
        } else {
            my = (x+1)/2;
            while (my * my > x) {
                my = (my * my + x) / (2 * my);
            }
        }
        return my;
    }
};

int main() {

    std::cout << sqrt(2147483647);
    return 0;
}