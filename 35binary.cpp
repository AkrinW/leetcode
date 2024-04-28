#include <vector>
#include <iostream>
using namespace std;


int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    vector<int> nums{0,1,3,5,6,7,8,9,10,11,12,13,14};
    int target = 17;
    int search = searchInsert(nums, target);
    cout << search;
    return 0;
}