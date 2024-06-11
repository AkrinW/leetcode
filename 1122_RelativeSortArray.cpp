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
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        std::unordered_map<int, int> map;
        for (auto u: arr2) {
            ++map[u];
        }
        std::vector<int> tmp;
        for (auto u: arr1) {
            if (map.count(u)) {
                ++map[u];
            } else {
                tmp.push_back(u);
            }
        }
        sort(tmp.begin(), tmp.end());
        int i = 0;
        for (auto u: arr2) {
            for (int j = 0; j < map[u]-1; ++j) {
                arr1[i] = u;
                ++i;
            }
        }
        for (auto u: tmp) {
            arr1[i] = u;
            ++i;
        }
        return arr1;
    }
};

int main() {
    return 0;
}