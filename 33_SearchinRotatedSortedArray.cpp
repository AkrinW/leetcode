#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        while (start <= end && nums[start] > nums[end]) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                if (target > nums[end] && nums[mid] < nums[start]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (target <= nums[end] && nums[mid] > nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        if (start > end) {
            end = start;
        }
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
        return -1; 
    }
};    

int main() {
    std::vector<int> nums = {5,1,2,3,4};

    Solution sol;
    std::cout << sol.search(nums,1);
    return 0;
}