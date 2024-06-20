#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <array>
#include <cctype>
#include <functional>
#include <ranges>
using namespace std;

//优化cin 和cout 速度
auto __FAST__IO__ = []() noexcept -> int {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    return 0;
}();

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int count{};
        const int n = nums.size();
        for(int i{};i<n-1;++i){
            for(int j{i+1};j<n;++j){
                int x = nums[i];
                while(x >= 10) x /= 10;
                int y = nums[j];
                while(y >= 10) y %= 10;
                if(gcd(x,y) == 1) count ++;
            }
        }
        return count;
    }
};
    }
};

int main() {
    return 0;
}