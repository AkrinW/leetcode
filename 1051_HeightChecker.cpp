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
    int heightChecker(vector<int>& heights) {
        vector<int> tmp = heights;
        sort(tmp.begin(),tmp.end());
        int check = 0;
        int n = tmp.size();
        for (int i = 0; i < n; ++i) {
            if (tmp[i] != heights[i]) {
                ++check;
            }
        }
        return check;
    }
};

int main() {
    return 0;
}