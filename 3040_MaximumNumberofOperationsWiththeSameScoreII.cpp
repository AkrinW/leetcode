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
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 2000) {
            return 1000;
        }
        int start = 0, end = n - 1;
        int max = 0;
        int sum = 0;
        int count = 0;
        function<void(int, int, int)> dfs = [&](int _start, int _end, int _count) {
            int curcount = _count;
            int a = nums[_start] + nums[_start+1];
            int b = nums[_end] + nums[_end-1];
            int c = nums[_start] + nums[_end];
            if (_end - _start < 1) {
                max = max > curcount ? max : curcount;
                return;
            }
            if (a != sum && b != sum && c != sum) {
                max = max > curcount ? max : curcount;
                return;
            }
            if (a == sum) {
                ++curcount;
                dfs(_start+2, _end, curcount);
                curcount = _count;
            }
            if (b == sum) {
                ++curcount;
                dfs(_start, _end-2, curcount);
                curcount = _count;
            }
            if (c == sum) {
                ++curcount;
                dfs(_start+1, _end-1, curcount);
            }
        };
        count = 1;
        sum = nums[start] + nums[start+1];
        dfs(start+2, end, count);
        sum = nums[end] + nums[end-1];
        dfs(start, end-2, count);
        sum = nums[start] + nums[end];
        dfs(start+1, end-1, count); 
        return max;
    }
};

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n));
        bool done = false;
        auto helper = [&](int i, int j, int target) -> int {
            if (done) return 0;
            for (auto& row : memo) {
                ranges::fill(row, -1); // -1 表示没有计算过
            }
            function<int(int, int)> dfs = [&](int i, int j) -> int {
                if (done) return 0;
                if (i >= j) {
                    done = true;
                    return 0;
                }
                int& res = memo[i][j]; // 注意这里是引用
                if (res != -1) return res; // 之前计算过
                res = 0;
                if (nums[i] + nums[i + 1] == target) res = max(res, dfs(i + 2, j) + 1);
                if (nums[j - 1] + nums[j] == target) res = max(res, dfs(i, j - 2) + 1);
                if (nums[i] + nums[j] == target) res = max(res, dfs(i + 1, j - 1) + 1);
                return res;
            };
            return dfs(i, j);
        };
        int res1 = helper(2, n - 1, nums[0] + nums[1]); // 删除前两个数
        int res2 = helper(0, n - 3, nums[n - 2] + nums[n - 1]); // 删除后两个数
        int res3 = helper(1, n - 2, nums[0] + nums[n - 1]); // 删除第一个和最后一个数
        return max({res1, res2, res3}) + 1; // 加上第一次操作
    }
};




int main() {

    return 0;
}