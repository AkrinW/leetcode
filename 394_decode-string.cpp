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
    string decodeString(string s) {
        int n = s.size();
        int i = 0, j = 0;
        string decode = "";
        stack<int> st1;
        stack<string> st2;
        st2.push("");

        function<int()> nextToken = [&]() {
            if (s[j] == ']') {
                ++j;
                return 0;
            } else if ('a' <= s[j] && s[j] <= 'z') {
                while (j < n && 'a' <= s[j] && s[j] <= 'z') {
                    ++j;
                }
                return 1;
            } else {
                while (s[j] != '[') {
                    ++j;
                }
                return 2;
            }
        };
        while (i < n) {
            int next = nextToken();
            if (next == 1) {
                string tmp = st2.top() + s.substr(i, j-i);
                st2.pop();
                st2.push(tmp);
            } else if (next == 2) {
                string tmp = s.substr(i, j - i);
                int count = stoi(tmp);
                st1.push(count);
                st2.push("");
                ++j;
            } else {
                string tmp = st2.top(), tmp2 = "";
                st2.pop();
                int count = st1.top();
                st1.pop();
                for (int x = 0; x < count; ++x) {
                    tmp2 += tmp;
                }
                tmp2 = st2.top() + tmp2;
                st2.pop();
                st2.push(tmp2);
            }
            i = j;
        }
        decode = st2.top();
        return decode;
    }
};

int main() {
    return 0;
}