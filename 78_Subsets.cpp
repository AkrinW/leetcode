#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <array>
#include <cctype>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> sub;
        sub.push_back(std::vector<int>());
        for (auto num : nums) {
            int s = sub.size();
            for (int i = 0; i < s; ++i) {
                std::vector<int> tmp = sub[i];
                tmp.push_back(num);
                sub.push_back(tmp);
            }
        }
        return sub;
    }
};

int main() {
    return 0;
}