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
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int max = 0;
        int minuteMax = 0;
        int tmp = 0;
        int i = 0;
        int count = 0;
        while (i < n) {
            if (grumpy[i] == 0) {
                max += customers[i];
            } else {
                tmp += customers[i];
            }
            ++count;
            if (count == minutes) {
                minuteMax = minuteMax > tmp ? minuteMax : tmp;
                if (grumpy[i - minutes + 1] == 1) {
                    tmp -= customers[i - minutes + 1];
                }
                --count;
            }
            ++i;
        }
        max += minuteMax;
        return max;
    }
};
int main() {
    return 0;
}