#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        std::vector<int> search;
        int s1,s2;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] >= target) {
                end = mid - 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            }
        }
        s1 = end;
        start = 0; 
        end = n - 1;
        while (start <= end) {
            int mid = (start + end) /2 ;
            if (nums[mid] <= target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        s2 = end + 1;
        if (s2 - s1 < 2) {
            search.push_back(-1);
            search.push_back(-1);
        }  else {
            search.push_back(s1+1);
            search.push_back(s2-1);
        }
        return search;
    }
};

int main() {
    std::vector<int> nums = {1,2,3,4,4,4,7};

    Solution sol;
    sol.searchRange(nums,1);
    return 0;
}