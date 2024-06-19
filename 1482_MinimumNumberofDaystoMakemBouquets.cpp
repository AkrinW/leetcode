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
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (long(n) < long(m) * long(k)) {
            return -1;
        }
        vector<int> p(bloomDay);
        sort(p.begin(), p.end());
        std::function<bool(int)> ifBouquets = [&] (int days) -> bool {
            int count = 0;
            int i = 0;
            int continu = 0;
            while (i < n) {
                if (bloomDay[i] <= days) {
                    ++continu;
                    if (continu == k) {
                        ++count;
                        if (count == m) {
                            return true;
                        }
                        continu = 0;
                    }
                } else {
                    continu = 0;
                }
                ++i;
            }
            return false;
        };
        int begin = 0, end = n - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (ifBouquets(p[mid])) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        return p[begin];
    }
};

int main() {
    Solution sol;
    std::vector<int> n = {1,10,3,10,2};
    sol.minDays(n, 3, 1);
    return 0;
}