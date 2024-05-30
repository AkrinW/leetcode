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
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> count,sum;
        count[0] = 1;
        sum[0] = -1;
        ++count[arr[0]];
        sum[arr[0]] = 0;
        int trip = 0;
        for (int i = 1; i < n; ++i) {
            arr[i] ^= arr[i-1];
            if (count.count(arr[i])) {
                trip += count[arr[i]] * (i-1) - sum[arr[i]];
            }
            sum[arr[i]] += i;
            ++count[arr[i]];
        }
        return trip;
    }
};

int main() {
    return 0;
}