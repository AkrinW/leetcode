#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <array>
#include <cctype>
#include <functional>

class Solution {
public:
    int beautifulSubsets(std::vector<int>& nums, int k) {
        int n = nums.size();
        int tmp[1002]{0};
        int sum = 0;
        std::function <void(int)> dfs = [&](int i) {
            ++sum;
            if (i == n) {
                return;
            }
            for (int j = i; j < n; ++j) {
                int t = nums[j];
                if ((t < k ||(t >= k && tmp[t-k] == 0)) && (t > 1000-k || (t <= 1000-k && tmp[t+k] == 0))) {
                    ++tmp[t];
                    dfs(j+1);
                    --tmp[t];
                }
            }
        };
        dfs(0);
        return sum;
    }
};

int main() {
    Solution sol;
    std::vector<int> p = {2,3,4,5,9,10};
    sol.beautifulSubsets(p,1);
    return 0;
}