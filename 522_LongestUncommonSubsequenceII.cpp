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
private:
    bool isSubstr(std::string u, std::string v) {
        int n1 = u.size();
        int n2 = v.size();
        int i = 0, j = 0;
        while (j < n2) {
            if (u[i] == v[j]) {
                ++i;
                if (i == n1) {
                    return true;
                }
            }
            ++j;
        }
        return false;
    }
public:
    int findLUSlength(vector<string>& strs) {
        unordered_map<std::string, int> map1, map2;
        int n = strs.size();
        for (int i = 0; i < n; ++i) {
            if (!map1.count(strs[i])) {
                ++map1[strs[i]];
            } else {
                --map1[strs[i]];
                ++map2[strs[i]];
            }
        }
        int longest = -1;
        for (auto u: map1) {
            bool flag = false;
            int n1 = u.first.size();
            for (auto v: map2) {
                flag = isSubstr(u.first, v.first);
                if (flag) {
                    break;
                }
            }
            if (!flag) {
                longest = longest > n1 ? longest : n1;
            }
        }
        return longest;
    }
};

int main() {
    Solution sol;
    std::vector<string> str = {"aba","cdc","eae"};
    sol.findLUSlength(str);
    return 0;
}