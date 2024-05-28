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
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int max = 0;
        int count = 0;
        int i = 0, j = 0;
        while (j < n) {
            int tmp = s[j] - t[j];
            if (tmp < 0) {
                tmp = -tmp;
            }
            maxCost -= tmp;
            if (maxCost >= 0) {
                ++j;
                ++count;
                max = max >= count ? max : count;
            } else {
                maxCost += tmp;
                if (i == j) {
                    ++i;
                    ++j;
                } else {
                    tmp = s[i] - t[i];
                    if (tmp < 0) {
                        tmp = -tmp;
                    }
                    maxCost += tmp;
                    ++i;
                    --count;
                }
            }
        }
        return max;
    }
};

// class Solution {
// public:
//     int equalSubstring(string s, string t, int maxCost) {
//         priority_queue<int> que;
//         int n = s.size();
//         int count = 0;
//         for (int i = 0; i < n; ++i) {
//             int tmp = s[i] - t[i];
//             if (tmp < 0) {
//                 tmp = - tmp;
//             }
//             if (tmp <= maxCost) {
//                 que.push(tmp);
//                 maxCost -= tmp;
//                 ++count;
//             } else {
//                 if (!que.empty() && tmp < que.top()) {
//                     maxCost -= tmp;
//                     maxCost += que.top();
//                     que.pop();
//                     que.push(tmp);
//                 }
//             }
//         }
//         return count;
//     }
// };

int main() {
    string s = "krrgw";
    string t = "zjxss";
    int maxCost = 19;
    Solution sol;
    sol.equalSubstring(s,t,maxCost);
    return 0;
}