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
    void reverseString(vector<char>& s) {
        int j = s.size() - 1;
        int i = 0;
        while (i < j) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            ++i;
            --j;
        }
    }
};

int main() {
    return 0;
}