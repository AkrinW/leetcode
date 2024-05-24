#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <array>
#include <cctype>
#include <functional>

class Solution {
public:
    std::vector<int> mostCompetitive(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> most;
        int start = 0;
        int *mostc = new int[k];
        // while (k > 0) {
        //     int min = 1e9;
        //     for (int i = start; i <= n - k; ++i) {
        //         if (nums[i] < min) {
        //             min = nums[i];
        //             start = i;
        //         }
        //     }
        //     most.push_back(min);
        //     ++start;
        //     --k;
        // }

        // for (int i = 0; i < n; ++i) {
        //     if (start == 0) {
        //         most.push_back(nums[i]);
        //         ++start;
        //     } else if (nums[i] < most[start-1]){
        //         while (start != 0 && nums[i] < most[start-1] && k-start < n-i) {
        //             most.pop_back();
        //             --start;
        //         }
        //         most.push_back(nums[i]);
        //         ++start;
        //     }
        // }

        for (int i = 0; i < n; ++i) {
            if (start == 0 || (nums[i] >= mostc[start-1] && start !=k)) {
                mostc[start] = nums[i];
                ++start;
            } else if (nums[i] < mostc[start-1]) {
                while (start != 0 && nums[i] < mostc[start-1] && k - start < n-i) {
                    --start;
                }
                mostc[start] = nums[i];
                ++start;
            }
        }
        for (int i = 0; i < k; ++i) {
            most.push_back(mostc[i]);
        }
        return most;
    }
};

int main() {
    return 0;
}