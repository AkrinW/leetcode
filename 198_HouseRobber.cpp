#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int n = nums.size();
        int robmoney1 = 0;
        int robmoney2 = 0;
        int robmoney3 = 0;
        for (int i = 0; i < n; ++i) {
            int t1 = robmoney1 + nums[i];
            int t2 = robmoney2 + nums[i];
            int tmp = robmoney3;
            robmoney3 = t1 > t2 ? t1 : t2;
            robmoney1 = robmoney2;
            robmoney2 = tmp;
        }
        return robmoney2 > robmoney3 ? robmoney2 : robmoney3;
    }
};

int main() {
    return 0;
}