#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        int max = -1e6;
        int dp = 0;
        int n = nums.size();
        int minPreSum = 0;
        int maxPreSum = 0;
        int minSum = 1e6;
        int maxSum = -1e6;
        for (int i = 0; i < n; ++i) {
            dp += nums[i];
            minSum = (dp - maxPreSum) < minSum ? (dp - maxPreSum) : minSum;
            maxSum = (dp - minPreSum) > maxSum ? (dp - minPreSum) : maxSum;
            maxPreSum = dp > maxPreSum ? dp : maxPreSum;
            minPreSum = dp < minPreSum ? dp : minPreSum;
        }
        if (dp == minSum) {
            max = maxSum;
        } else {
            max = maxSum > (dp - minSum) ?  maxSum : (dp - minSum);
        }
        return max;
    }
};

int main() {
    std::vector<int> nums = {5,-3,5};
    Solution sol;
    int max = sol.maxSubarraySumCircular(nums);
    return 0;
}