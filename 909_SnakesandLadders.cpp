#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>

class Solution {
public:
    int snakesAndLadders(std::vector<std::vector<int>>& board) {
        int n = board.size();
        int num = n*n;
        int *step = new int[num+1];
        std::unordered_map<int,std::pair<int,int>> map;
        std::queue<int> que;
        bool flag = true;
        int x = n-1;
        int y = 0;
        for (int i = 1; i <= num; ++i) {
            step[i] = num;
            map[i] = {x,y};
            if (flag) {
                ++y;
                if (y == n) {
                    --y;
                    --x;
                    flag = false;
                }
            } else {
                --y;
                if (y == -1) {
                    ++y;
                    --x;
                    flag = true;
                }
            }
        }
        step[1] = 0;
        que.push(1);
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            int s = step[now];
            for (int i = 1; i <= 6; ++i) {
                int next = now + i;
                if (next > num) {
                    break;
                }
                int x_next = map[next].first;
                int y_next = map[next].second;
                if (board[x_next][y_next] != -1) {
                    next = board[x_next][y_next];
                }
                if (s + 1 < step[next]) {
                    step[next] = s+1;
                    que.push(next);
                }
            }
        }
        if (step[num] == num) {
            step[num] = -1;
        }
        return step[num];
    }
};

int main() {
    std::vector<std::vector<int>> board = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    Solution sol;
    int a = sol.snakesAndLadders(board);
    return 0;
}