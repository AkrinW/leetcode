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
    vector<int> findAnagrams(string s, string p) {
        vector<int> ansr{};
        int nums = s.size(), nump = p.size();
        if (nump > nums) {
            return ansr;
        }
        vector<int> count(26,0);
        for (int i = 0; i < nump; ++i) {
            ++count[s[i]-'a'];
            --count[p[i]-'a'];
        }
        int diff = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) {
                ++diff;
            }
        }
        if (diff == 0) {
            ansr.push_back(0);
        }
        for (int i = 0; i < nums - nump; ++i) {
            if (count[s[i]-'a'] == 1) {
                --diff;
            } else if (count[s[i]-'a'] == 0) {
                ++diff;
            }
            --count[s[i] - 'a'];
            if (count[s[i+nump]-'a'] == -1) {
                --diff;
            } else if (count[s[i+nump]-'a'] == 0) {
                ++diff;
            }
            ++count[s[i+nump]-'a'];
            if (diff == 0) {
                ansr.push_back(i+1);
            }
        }
        return ansr;
    }
};

int main() {
    return 0;
}