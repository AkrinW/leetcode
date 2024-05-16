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
    int minDistance(std::string word1, std::string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        std::vector<std::vector<int>> p(n1+1,std::vector<int>(n2+1));
        for (int i = 0; i < n1 + 1; ++i) {
            p[i][0] = i;
        }
        for (int j = 1; j < n2 + 1; ++j) {
            p[0][j] = j;
        }
        for (int i = 1; i < n1 + 1; ++i) {
            for (int j = 1; j < n2 + 1; ++j) {
                int a = p[i-1][j] + 1;
                int b = p[i][j-1] + 1;
                int c = p[i-1][j-1];
                a = a < b ? a : b;
                if (word1[i-1] != word2[j-1]) {
                    ++c;
                }
                p[i][j] = a < c ? a : c;
            }
        }
        return p[n1][n2];
    }
};

int main() {
    return 0;
}