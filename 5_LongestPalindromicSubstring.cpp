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
    std::string longestPalindrome(std::string s) {
        int n = s.size();
        std::string longest = "";
        // int **p = new int*[n];
        // for (int i = 0; i < n; ++i) {
        //     p[i] = new int[n];
        //     p[i][i] = 1;
        // }
        int x, y;
        std::vector<std::vector<bool>> p(n,std::vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = n-1; j >= i; --j) {
                int k = j - i;
                if (s[j] == s[k] && (i == 0 || i == 1 || p[k+1][j-1] == 1)) {
                    p[k][j] = true;
                    x = k;
                    y = i + 1;
                } else {
                    p[k][j] = 0;
                }
            }
        }
        longest = s.substr(x,y);
        return longest;
    }
};

int main() {
    return 0;
}