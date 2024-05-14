#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        while (nums[start] > nums[end]) {
            int mid = (start + end) / 2;
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return nums[start];
    }
};

int main() {
    std::vector<int> nums = {1,2,3,4,4,4,7};

    Solution sol;
    sol.findMin(nums);
    return 0;
}