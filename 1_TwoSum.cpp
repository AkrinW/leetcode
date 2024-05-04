#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int target = 8;
    int a[4] = {3,2,4,4};
    std::vector<int> nums(a,a+4);
    int n = nums.size();
    std::unordered_map<int, int> map;
    std::vector<int> two;
    for (int i = 0; i < n; ++i) {
        if (!map.count(nums[i])) {
            map[nums[i]] = i;
        }
        if (map.count(target-nums[i]) && map[target-nums[i]] != i) {
            two.push_back(i);
            two.push_back(map[target-nums[i]]);
            break;
        }
    }



    return 0;
}