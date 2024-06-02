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
    int distributeCandies(vector<int>& candyType) {
        std::unordered_map<int,int> map;
        int n = candyType.size();
        int distri = 0;
        for (int i = 0; i < n; ++i) {
            if (!map.count(candyType[i])) {
                ++map[candyType[i]];
                ++distri;
                if (distri == n / 2) {
                    break;
                }
            }
        }
        return distri;
    }
};

int main() {
    return 0;
}