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
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int n = items.size();
        sort(items.begin(),items.end());
        int category = 0;
        long long sum = 0;
        unordered_map<int, int> map;
        int i;
        for (i = n - k; i < n; ++i) {
            sum += long(items[i][0]);
            if (!map.count(items[i][1])) {
                ++category;
                sum += 2 * category - 1;
            }
            ++map[items[i][1]];
        }
        long long max = sum;
        i = n - k;
        int j = n - k - 1;
        while (category < k && i < n && j >= 0) {
            if (map[items[i][1]] == 1) {
                ++i;
                continue;
            } else {
                if (map.count(items[j][1])) {
                    --j;
                    continue;
                } else {
                    sum += items[j][0] - items[i][0];
                    ++category;
                    --map[items[i][1]];
                    ++map[items[j][1]];
                    sum += 2 * category - 1;
                    max = max > sum ? max : sum;
                    ++i;
                    --j;
                }
            }
        }
        return max;
    }
};

int main() {
    return 0;
}