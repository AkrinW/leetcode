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
    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        // int *len = new int[2502];
        // len[0] = 0;
        // len[1] = nums[0];
        std::vector<int> len;
        len.push_back(0);
        len.push_back(nums[0]);
        int maxlen = 1;
         for (int i = 1; i < n; ++i) {
            if (nums[i] > len[maxlen]) {
                ++maxlen;
                // len[maxlen] = nums[i];
                len.push_back(nums[i]);
            } else {
                int start = 1;
                int end = maxlen;
                while (start <= end) {
                    int mid = (start + end) / 2;
                    if (len[mid] == nums[i]) {
                        start = mid;
                        end = mid-1;
                    } else if (len[mid] < nums[i]) {
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
                len[start] = nums[i];
            }
        }
        // delete [] len;
        return maxlen;
    }
};

int main() {
    std::vector<int> nums = {3,5,6,2,5,4,19,5,6,7,12};
    Solution sol;
    sol.lengthOfLIS(nums);

    return 0;
}