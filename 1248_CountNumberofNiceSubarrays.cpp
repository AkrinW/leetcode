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
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0, p = -1, q = 0;
        int numbers = 0;
        while (i < n) {
            if (nums[i] % 2 == 1) {
                break;
            }
            ++i;
        }
        j = i;
        while (j < n && k != 0) {
            if (nums[j] % 2 == 1) {
                --k;
                if (k == 0) {
                    break;
                }
            }
            ++j;
        }
        if (k != 0) {
            return 0;
        }
        q = j + 1;
        while (q < n+1) {
            while (q < n && nums[q] % 2 == 0) {
                ++q;
            }
            numbers += (i-p) * (q-j);
            j = q;
            p = i;
            ++i;
            ++q;
            while (i < n && nums[i] % 2 == 0) {
                ++i;
            }
        }
        return numbers;
    }
};

int main() {
    return 0;
}