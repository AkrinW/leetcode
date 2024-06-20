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
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int avr = (position[n-1] - position[0]) / (m - 1);
        int start = 1, end = avr;
        std::function<bool(int)> ifMagnetic = [&] (int _mid) -> bool {
            int count = 1;
            int i = 1;
            int tmp = _mid + position[0];
            while (i < n) {
                if (position[i] >= tmp) {
                    ++count;
                    tmp = position[i] + _mid;
                    if (count == m) {
                        return true;
                    }
                }
                ++i;
            }
            return false;
        };
        while (start <= end) {
            int mid = (start + end) / 2;
            if (ifMagnetic(mid)) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return end;
    }
};

int main() {
    return 0;
}