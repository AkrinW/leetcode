#include <iostream>
#include <vector>
//considering too much in get answer in one traverse.
//it's ok in traverse 2 or 3 times with O(N).
int main() {
    int a[4] = {1,2,3,4};
    std::vector<int> nums(a, a+4); 

    std::vector<int> left(4);
    left[0] = 1;
    for (int i = 1; i < nums.size(); ++i) {
        left[i] = left[i-1] * nums[i-1];
    }
    int right = 1;
    for (int i = nums.size() - 2; i >= 0; --i) {
        right *= nums[i+1];
        left[i] *= right;
    }
    std::cout << left[0] << left[1] <<left[2] << left[3];

    return 0;
}