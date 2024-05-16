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
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        std::vector<int> p1(n+1), p2(n+1);
        p1[0] = 0;
        int small = 1e6;
        for (int i = 1; i < n + 1; ++i) {
            small = small < prices[i-1] ? small : prices[i-1];
            int tmp = prices[i-1] - small;
            p1[i] = p1[i-1] > tmp ? p1[i-1] : tmp;
        }
        p2[n] = 0;
        int max = -1;
        for (int i = n-1; i >= 0; --i) {
            max = max > prices[i] ? max : prices[i];
            int tmp = max - prices[i];
            p2[i] = p2[i] > tmp ? p2[i] : tmp;
        }
        int maxpro = 0;
        for (int i = 0; i < n+1; ++i) {
            int tmp = p1[i] + p2[i];
            maxpro = maxpro > tmp ? maxpro : tmp;
        }
        return maxpro;
    }
};

int main() {
    return 0;
}