#include <iostream>
#include <vector>

int main() {
    int a[6] ={2,3,1,2,4,3};
    std::vector<int> nums(a,a+6);
    int n = nums.size();
    int target = 7;
    int sum = 0;
    int len = 1e6;
    int i = 0;
    int j = 0;
    int tmp = 0;
    sum = nums[0];
    while (j < n) {
        if (sum >= target) {
            tmp = j - i + 1;
            len = len < tmp ? len : tmp;
            ++i;
            sum -= nums[i-1];
            if (i > j) {
                break;
            }
        } else {
            ++j;
            if (j == n) {
                break;
            }
            sum += nums[j];
        }
    }
    if (j == n && i == 0) {
        len = 0;
    }
    std::cout << len;
    

    return 0;
}