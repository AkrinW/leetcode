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
    int longestPalindrome(string s) {
        int arr['z'-'A'+1]{0};
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            ++arr[s[i]-'A'];
        }
        n = 0;
        int longest = 0;
        for (int i = 0; i < 'z'-'A' + 1;++i) {
            longest += arr[i];
            if (arr[i] % 2 == 1) {
                --longest;
                ++n;
            }
        }
        if (n) {
            ++longest;
        }
        return longest;
    }
};

int main() {
    return 0;
}