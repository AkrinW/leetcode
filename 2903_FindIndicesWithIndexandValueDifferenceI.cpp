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
using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        int i = 0, j = n-1;
        std::vector<int> find;
        std::vector<int> max(n-indexDifference,0);
        std::vector<int> min(n-indexDifference,0);
        for (int i = 1; i < n-indexDifference; ++i) {
            if (nums[i] > nums[max[i-1]]) {
                max[i] = i;
            } else {
                max[i] = max[i-1];
            }
            if (nums[i] < nums[min[i-1]]) {
                min[i] = i;
            } else {
                min[i] = min[i-1];
            }
        }
        for (int i = n-1; i >= indexDifference; --i) {
            if (nums[i] - nums[min[i-indexDifference]] >= valueDifference) {
                find.push_back(i);
                find.push_back(min[i-indexDifference]);
                break;
            } else if (nums[max[i-indexDifference]] - nums[i] >= valueDifference) {
                find.push_back(i);
                find.push_back(max[i-indexDifference]);
                break;
            }
        }
        if (find.size() == 0) {
            find.push_back(-1);
            find.push_back(-1);
        }
        return find;
    }
};

int main() {
    vector<int> nums{5,1,4,1};
    Solution sol;
    sol.findIndices(nums,2,4);
    return 0;
}