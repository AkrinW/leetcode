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
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int t = purchaseAmount % 10;
        if (t < 5) {
            purchaseAmount = 100 - purchaseAmount + t;
        } else {
            purchaseAmount = 90 - purchaseAmount + t;
        }
        return purchaseAmount;
    }
};

int main() {
    return 0;
}