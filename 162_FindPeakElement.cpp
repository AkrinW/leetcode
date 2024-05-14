#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (mid != 0 && nums[mid]  < nums[mid - 1]) {
                end = mid - 1;
            } else if (mid != n-1 && nums[mid] < nums[mid + 1]) {
                start = mid + 1;
            } else {
                return mid;
            }
        }
        return start;
    }
};

int main() {
    Solution sol;
    return 0;
}