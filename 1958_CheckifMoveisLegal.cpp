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
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        bool flag = false;
        int i = rMove, j = cMove;
        while (i > 0) {
            --i;
            if (board[i][j] == '.' || board[i][j] == color) {
                break;
            }
        }
        if (i >= 0 && board[i][j] == color && rMove - i > 1) {
            return true;
        }
        i = rMove;
        while (i < 7) {
            ++i;
            if (board[i][j] == '.' || board[i][j] == color) {
                break;
            }
        }
        if (i <= 7 && board[i][j] == color && i - rMove > 1) {
            return true;
        }
        i = rMove;
        while (j > 0) {
            --j;
            if (board[i][j] == '.' || board[i][j] == color) {
                break;
            }
        }
        if (j >= 0 && board[i][j] == color && cMove - j > 1) {
            return true;
        }
        j = cMove;
        while (j < 7) {
            ++j;
            if (board[i][j] == '.' || board[i][j] == color) {
                break;
            }
        }
        if (j <= 7 && board[i][j] == color && j - cMove > 1) {
            return true;
        }
        j = cMove;
        while (i > 0 && j > 0) {
            --i;
            --j;
            if (board[i][j] == '.' || board[i][j] == color) {
                break;
            }
        }
        if (i >= 0 & j >= 0 && board[i][j] == color && rMove - i > 1) {
            return true;
        }
        i = rMove;
        j = cMove;
        while (i < 7 && j < 7) {
            ++i;
            ++j;
            if (board[i][j] == '.' || board[i][j] == color) {
                break;
            }
        }
        if (i <= 7 & j <= 7 && board[i][j] == color && i - rMove > 1) {
            return true;
        }
        i = rMove;
        j = cMove;
        while (i > 0 && j < 7) {
            --i;
            ++j;
            if (board[i][j] == '.' || board[i][j] == color) {
                break;
            }
        }
        if (i >= 0 & j <= 7 && board[i][j] == color && rMove - i > 1) {
            return true;
        }
        i = rMove;
        j = cMove;
        while (i < 7 && j > 0) {
            ++i;
            --j;
            if (board[i][j] == '.' || board[i][j] == color) {
                break;
            }
        }
        if (i <= 7 & j >= 0 && board[i][j] == color && i - rMove > 1) {
            return true;
        }
        return false;
    }
};

int main() {
    return 0;
}