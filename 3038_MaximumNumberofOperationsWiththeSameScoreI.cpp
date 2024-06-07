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
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int sum = nums[0] + nums[1];
        for (int i = 2; i < n-1; i += 2) {
            int tmp = nums[i] + nums[i+1];
            if (tmp != sum) {
                break;
            }
            ++count;
        }      
        return count;
    }
};

int main() {
    return 0;
}