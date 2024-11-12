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
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int orangesum = 0;
        int currot = 0;
        int time = 0;
        queue<pair<int, int>> que;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++orangesum;
                } else if (grid[i][j] == 2) {
                    que.push({i,j});
                    ++currot;
                }
            }
        }
        while (orangesum && currot) {
            int nextrot = 0;
            for (int i = 0; i < currot; ++i) {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                if (x > 0 && grid[x-1][y] == 1) {
                    ++nextrot;
                    --orangesum;
                    grid[x-1][y] = 2;
                    que.push({x-1,y});
                }
                if (x < m-1 && grid[x+1][y] == 1) {
                    ++nextrot;
                    --orangesum;
                    grid[x+1][y] = 2;
                    que.push({x+1,y});
                }
                if (y > 0 && grid[x][y-1] == 1) {
                    ++nextrot;
                    --orangesum;
                    grid[x][y-1] = 2;
                    que.push({x,y-1});
                }
                if (y < n-1 && grid[x][y+1] == 1) {
                    ++nextrot;
                    --orangesum;
                    grid[x][y+1] = 2;
                    que.push({x,y+1});
                }
            }
            currot = nextrot;
            ++time;
        }
        if (orangesum) {
            return -1;
        }
        return time;
    }
};

int main() {
    return 0;
}