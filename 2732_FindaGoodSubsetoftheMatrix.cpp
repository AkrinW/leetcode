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
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_map<int, int> mp;
        int m = grid.size();
        int n = grid[0].size();

        for (int j = 0; j < m; j++) {
            int st = 0;
            for (int i = 0; i < n; i++) {
                st |= (grid[j][i] << i);
            }
            mp[st] = j;
        }

        if (mp.count(0)) {
            ans.push_back(mp[0]);
            return ans;
        }

        for (auto [x, i]: mp) {
            for (auto [y, j]: mp) {
                if (!(x & y)) {
                    return {min(i, j), max(i, j)};
                }
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}