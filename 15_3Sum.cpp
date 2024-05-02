#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    int a[6] = {-1,0,1,2,-1,-4};
    std::vector<int> nums(a,a+6);
    int n = nums.size();
    std::vector<std::vector<int>> threesum;
    std::sort(nums.begin(), nums.end());
    int two = 0;
    for (int i = 0; i < n-2; ++i) {
        if (nums[i] > 0) {
            break;
        }
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        int one = -nums[i];
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            if (nums[j] > one/2 || nums[k] < one/2) {
                break;
            }
            two = nums[j] + nums[k];
            if (two < one || (j > i + 1 && nums[j] == nums[j-1])) {
                ++j;
            } else if (two > one || (k < n-1 && nums[k] == nums[k+1])) {
                --k;
            } else {
                int temp[3] = {nums[i],nums[j],nums[k]};
                std::vector<int> tmp(temp, temp+3);
                threesum.push_back(tmp);
                ++j;
                --k;
            }
        }
    }
    for (int i = 0; i < threesum.size();++i) {
        std::cout << threesum[i][0] << threesum[i][1] << threesum[i][2] << std::endl;
    }


    return 0;
}