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
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }
        unordered_map<int, int> map;
        priority_queue<int, vector<int>, greater<int>> que;
        for (int i = 0; i < n; ++i) {
            ++map[hand[i]];
            que.push(hand[i]);
        }
        while (!que.empty()) {
            n = que.top();
            que.pop();
            if (map[n] == 0) {
                continue;
            }
            for (int i = 0; i < groupSize; ++i) {
                if (map[n+i] == 0) {
                    return false;
                }
                --map[n+i];
            }
        }
        return true;
    }
};

int main() {
    return 0;
}