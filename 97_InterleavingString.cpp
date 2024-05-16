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
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if (n3 != n1 + n2) {
            return false;
        }
        if (n3 == 0) {
            return true;
        }
        std::vector<std::vector<bool>> p(n1+1,std::vector<bool>(n2+1));
        p[0][0] = true;
        for (int i = 0; i < n3; ++i) {
            for (int j = -1; j <= i && j < n1; ++j) {
                int k = i - j - 1;
                if (k >= n2) {
                    continue;
                }
                if (j == -1) {
                    if (s2[k] == s3[i] && p[0][k]) {
                        p[0][k+1] = true;
                    } else {
                        p[0][k+1] = false;
                    }
                } else if (k == -1) {
                    if (s1[j] == s3[i] && p[j][0]) {
                        p[j+1][0] = true;
                    } else {
                        p[j+1][0] = false;
                    }
                } else {
                    if ((s2[k] == s3[i] && p[j+1][k]) || (s1[j] == s3[i] && p[j][k+1])) {
                        p[j+1][k+1] = true;
                    } else {
                        p[j+1][k+1] = false;
                    }
                }
            }
        }
        return p[n1][n2];
    }
};

int main() {
    return 0;
}