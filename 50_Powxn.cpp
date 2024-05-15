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
    double myPow(double x, int n) {
        double my = 1;
        if (n == 0 || x == 1) {
            return 1;
        } else if (x == 0) {
            return 0;
        }
        if (n == -2147483648) {
            ++n;
            my *= x;
        }
        if (n < 0) {
            n = -n;
            double con = x;
            while (n > 0) {
                if (n % 2 == 1) {
                    my *= con;
                }
                n >>= 1;
                con *= con;
            }
            my = 1/my;
        } else {
            double con = x;
            while (n > 0) {
                if (n % 2 == 1) {
                    my *= con;
                }
                n >>= 1;
                con *= con;
            }
        }
        return my;
    }
};

int main() {

}