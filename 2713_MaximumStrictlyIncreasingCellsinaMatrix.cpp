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
    int maxIncreasingCells(vector<vector<int>>& mat) {
        vector<pair<int, pair<int, int>>> list;
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                list.push_back({mat[i][j], {i, j}});
            }
        }
        sort(list.begin(), list.end());
        int max = 0;
        int curnum = INT_MIN;
        vector<int> vertic(m, 0);
        vector<int> horiz(n, 0);
        // vector<int> vertic_tmp(m, 0);
        // vector<int> horiz_tmp(n, 0);
        unordered_map<int, int> map1, map2;
        for (auto u : list) {
            if (u.first > curnum) {
                for (auto _m: map1) {
                    vertic[_m.first] = _m.second;
                }
                for (auto _m: map2) {
                    horiz[_m.first] = _m.second;
                }
                map1.clear();
                map2.clear();
                curnum = u.first;
            }
            auto sub = u.second;
            int x1 = sub.first;
            int x2 = sub.second;
            int tmp = std::max(vertic[x1], horiz[x2]) + 1;
            max = max > tmp ? max : tmp;
            map1[x1] = map1[x1] > tmp ? map1[x1] : tmp;
            map2[x2] = map2[x2] > tmp ? map2[x2] : tmp;
            // vertic_tmp[x1] = vertic_tmp[x1] > tmp ? vertic_tmp[x1] : tmp;
            // horiz_tmp[x2] = vertic_tmp[x2] > tmp ? vertic_tmp[x2] : tmp;
        }
        return max;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{-4,8,-3,2,-4,-8,7,5,-2},{-5,5,-7,-2,6,-6,-8,-4,-4}};
    sol.maxIncreasingCells(mat);
    return 0;
}