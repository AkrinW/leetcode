#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int a[6] = {1,2,3,1,2,3};
    std::vector<int> nums(a,a+6);
    int k = 4;
    int n = nums.size();
    std::unordered_map<int, int> map;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (map.count(nums[i]) && (i - map[nums[i]] <= k)) {
            flag = true;
            break;
        }
        map[nums[i]] = i;
    }
    std::cout << flag;

    return 0;
}