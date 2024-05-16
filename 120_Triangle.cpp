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
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        int num = triangle.size();
        for (int i = 1; i < num; ++i) {
            triangle[i][0] += triangle[i-1][0];
            triangle[i][i] += triangle[i-1][i-1];
            for (int j = 1; j < i; ++j) {
                int a = triangle[i-1][j-1];
                int b = triangle[i-1][j];
                a = a < b ? a : b;
                triangle[i][j] += a;
            }
        }
        int min = triangle[num-1][0];
        for (int i = 1; i < num; ++i) {
            min = min < triangle[num-1][i] ? min : triangle[num-1][i];
        }
        return min;
    }
};

int main() {
    return 0;
}