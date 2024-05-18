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
    int maxDivScore(std::vector<int>& nums, std::vector<int>& divisors) {
        int n1 = nums.size();
        int n2 = divisors.size();
        int maxdiv = 0;
        int maxnum = INT_MAX;
        for (int i = 0; i < n2; ++i) {
            int tmpdiv = 0;
            for (int j = 0; j < n1; ++j) {
                if (n1-j + tmpdiv < maxdiv) {
                    break;
                }
                if (nums[j] % divisors[i] == 0) {
                    ++tmpdiv;
                    if (tmpdiv > maxdiv) {
                        ++maxdiv;
                        maxnum = divisors[i];
                    }
                }
            }
            if (tmpdiv == maxdiv) {
                maxnum = maxnum < divisors[i] ? maxnum : divisors[i];
            }
        }
        return maxnum;
    }
};