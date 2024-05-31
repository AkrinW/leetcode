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
using namespace std;

//优化cin 和cout 速度
auto __FAST__IO__ = []() noexcept -> int {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    return 0;
}();

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int sum1 = n*n*(n*n+1)/2;
        int sum2 = n*n*(n*n+1)*(2*n*n+1)/6;
        int sumx = 0,sumy = 0;
        for (auto u : grid) {
            for (auto v : u) {
                sumx += v;
                sumy += v * v;
            }
        }
        sum1 = sumx - sum1;
        sum2 = (sumy-sum2)/sum1;
        sumx = (sum1+sum2)/2;
        sumy = sum2 - sumx;
        return std::vector<int>{sumx,sumy};
    }
};

int main() {
    return 0;
}