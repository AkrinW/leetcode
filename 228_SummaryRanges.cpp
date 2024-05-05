#include <iostream>
#include <vector>
#include <string>

int main() {
    int a[6] = {0,1,2,4,5,7};
    std::vector<int> nums(a,a+6);
    int n = nums.size();
    std::vector<std::string> summary;
    if (n == 0) {
        return 0;
    }
    std::string s = "";
    s += std::to_string(nums[0]);
    int sub = 0;
    for (int i = 1; i < n; ++i) {
        if (nums[i] - 1 != nums[i-1]) {
            if (i-1 != sub) {
                s += "->";
                s += std::to_string(nums[i-1]);
            }
            summary.push_back(s);
            s = std::to_string(nums[i]);
            sub = i;
        }
    }
    if (sub != n - 1) {
        s += "->";
        s += std::to_string(nums[n-1]);
    }
    summary.push_back(s);
    std::cout << summary[0];
    return 0;
}