#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <array>
#include <cctype>
#include <functional>
using namespace std;

//优化cin 和cout 速度
auto __FAST__IO__ = []() noexcept -> int {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    return 0;
}();

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        vector<int> miss;
        int sum = (m+n) * mean;
        for (auto r : rolls) {
            sum -= r;
        }
        double avr = double(sum) / double(n);
        if (avr < 1 || avr > 6) {
            return miss;
        }
        int small = int(avr);
        int y = sum - small * n;
        int x = n - y;
        for (int i = 0; i < x; ++i) {
            miss.push_back(small);
        }
        ++small;
        for (int i = 0; i < y; ++i) {
            miss.push_back(small);
        }
        return miss;
    }
};


int main (){
    return 0;
}