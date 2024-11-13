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
    vector<int> partitionLabels(string s) {
        vector<int> partition;
        int n = s.size();
        int ch[26] = {0};
        int cursplit = 0;
        for (int i = 0; i < n; ++i) {
            int tmp = s[i] - 'a';
            if (ch[tmp] == 0) {
                ++cursplit;
                ch[tmp] = cursplit;
                partition.push_back(1);
            } else {
                ++partition[cursplit-1];
                while (cursplit > ch[tmp]) {
                    partition[cursplit-2] += partition[cursplit-1];
                    partition.pop_back();
                    --cursplit;
                }
                for (int i = 0; i < 26; ++i) {
                    if (ch[i] > cursplit) {
                        ch[i] = cursplit;
                    }
                }
            }
        }
        return partition;
    }
};


int main() {
    return 0;
}