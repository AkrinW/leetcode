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
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int len = 0;
        std::vector<std::vector<int>> p(m,std::vector<int>(n));
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    p[i][j] = 0;
                } else if (i == 0 || j == 0) {
                    p[i][j] = 1;
                    if (len == 0) {
                        ++len;
                    }
                } else {
                    int tmp = p[i-1][j-1] < p[i-1][j] ? p[i-1][j-1] : p[i-1][j];
                    p[i][j] = tmp+1 < p[i][j-1] + 1 ? tmp + 1 : p[i][j-1] + 1;
                    if (p[i][j] > len) {
                        len = p[i][j];
                    }   
                }
            }
        }
        return len*len;
    }
};

int main() {
    return 0;
}