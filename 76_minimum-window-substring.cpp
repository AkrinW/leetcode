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
    string minWindow(string s, string t) {
        int nums = s.size(), numt = t.size();
        if (nums < numt) {
            return "";
        }
        vector<int> count(128,0);
        for (int i = 0; i < numt; ++i) {
            --count[t[i]];
            ++count[s[i]];
        }
        int diff = 0;
        for (int i = 0; i < 128; ++i) {
            if (count[i] < 0) {
                --diff;
            }
        }
        int maxstart = 0, maxlength = INT_MAX;
        int start = 0, end = numt;
        while (true) {
            if (diff < 0) { // 扩充区间
                while (end < nums) {
                    ++count[s[end]];
                    if (count[s[end]] == 0) {
                        ++diff;
                    }
                    ++end;
                    if (diff == 0) {
                        break;
                    }
                }
                if (end == nums && diff < 0) {
                    break;
                }
            } else { // 压缩区间
                --count[s[start]];
                if (count[s[start]] == -1) {
                    --diff;
                    int tmplen = end - start;
                    if (tmplen < maxlength) {
                        maxlength = tmplen;
                        maxstart = start;
                    }
                }
                ++start;
            }
        }
        if (maxlength == INT_MAX) {
            return "";
        }
        return s.substr(maxstart, maxlength);
    }
};

int main() {
    return 0;
}