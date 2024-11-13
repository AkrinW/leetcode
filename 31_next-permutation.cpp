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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//优化cin 和cout 速度
auto __FAST__IO__ = []() noexcept -> int {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    return 0;
}();

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int swap = n-1;
        while (swap > 0) {
            if (nums[swap] > nums[swap-1]) {
                // 找到了 开始交换。
                int tmp;
                int i = swap;
                while (i < n && nums[i] > nums[swap-1]) {
                    ++i;
                }
                tmp = nums[swap-1];
                nums[swap-1] = nums[i-1];
                nums[i-1] = tmp;

                i = n-1;
                while (swap < i) {
                    tmp = nums[swap];
                    nums[swap] = nums[i];
                    nums[i] = tmp;
                    ++swap;
                    --i;
                }
                return;
            } else {
                --swap;
            }
        }
        // 没找到，把整个数组倒序
        --n;
        while (swap < n) {
            int tmp = nums[swap];
            nums[swap] = nums[n];
            nums[n] = tmp;
            --n;
            ++swap;
        }
        return;
    }
};
int main() {
    return 0;
}