#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j <n; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                } else if (i == 0) {
                    grid[0][j] += grid[0][j-1];
                } else if (j == 0) {
                    grid[i][0] += grid[i-1][0];
                } else {
                    int tmp = grid[i][j-1] < grid[i-1][j] ? grid[i][j-1] : grid[i-1][j];
                    grid[i][j] += tmp;
                }
            }
        }
        return grid[m-1][n-1];
    }
};

int main() {
    return 0;
}