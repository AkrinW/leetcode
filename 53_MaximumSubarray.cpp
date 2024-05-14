#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int max = -1e6;
        int n = nums.size();
        int dp = -1e6;
        for (int i = 0; i < n; ++i) {
            if (dp <= 0) {
                dp = nums[i];
            } else {
                dp += nums[i];
            }
            max = dp > max ? dp : max;
        }
        return max;
    }
};

int main() {
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    int n = sol.maxSubArray(nums);
    return 0;
}