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
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i = 0, j = people.size() - 1;
        int num = 0;
        while (i < j) {
            if (people[i] + people[j] <= limit) {
                ++i;
            }
            --j;
            ++num;
        }
        if (i == j) {
            ++num;
        }
        return num;
    }
};

int main() {
    return 0;
}