#include <iostream>
#include <vector>
#include <unordered_map>


//use unordered_map hash table to solve the problem
//map<int,int> save num and it's longestconsecutivesequence
//check .count(num-1) and .count(num+1).if true, update the longest
//only need to update the begin and end number, ignore middle
//O(n)
int main() {
    int a[6] = {100,4,200,1,3,2};
    std::vector<int> nums(a,a+6);
    int n = nums.size();
    std::unordered_map<int, int> map;
    int len = 0;
    for (int i = 0; i < n; ++i) {
        if (!map.count(nums[i])) {
            if (map.count(nums[i] - 1) && map.count(nums[i] + 1)) {
                int a = map[nums[i]-1];
                int b = map[nums[i]+1];
                map[nums[i]-a] = a+b+1;
                map[nums[i]+b] = a+b+1;
                map[nums[i]] = 0;
                len = len >= a+b+1 ? len : a + b + 1;
            } else if (map.count(nums[i] - 1)) {
                int a = map[nums[i]-1];
                ++map[nums[i]-a];
                map[nums[i]] = a + 1;
                len = len >= a+1 ? len : a+1; 
            } else if (map.count(nums[i] + 1)) {
                int b = map[nums[i] + 1];
                ++map[nums[i]+b];
                map[nums[i]] = b + 1;
                len = len >= b+1 ? len : b+1;
            } else {
                map[nums[i]] = 1;
                len = len >= 1 ? len : 1;
            }
        }
    }
    std::cout << len;

    return 0;
}