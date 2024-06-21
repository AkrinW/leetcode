#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <array>
#include <cctype>
#include <functional>
#include <ranges>
using namespace std;

//优化cin 和cout 速度
auto __FAST__IO__ = []() noexcept -> int {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    return 0;
}();

class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int n = temperatureA.size();
        int i = 0;
        int a = 0, b = 0;
        int max = 0;
        int tmp = 0;
        while (i < n - 1) {
            a = temperatureA[i+1] - temperatureA[i];
            if (a > 0) {
                a = 1;
            } else if (a < 0) {
                a = -1;
            } else {
                a = 0;
            }
            b = temperatureB[i+1] - temperatureB[i];
            if (b > 0) {
                b = 1;
            } else if (b < 0) {
                b = -1;
            } else {
                b = 0;
            }
            if (a == b) {
                ++tmp;
                max = max > tmp ? max : tmp;
            } else {
                tmp = 0;
            }
            ++i;
        }
        return max;
    }
};

int main() {
    return 0;
}