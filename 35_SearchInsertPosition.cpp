#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }
};



int main() {
    std::vector<int> nums{0,1,3,5,6,7,8,9,10,11,12,13,14};
    Solution sol;
    int target = 17;
    int search = sol.searchInsert(nums, target);
    std::cout << search;
    return 0;
}