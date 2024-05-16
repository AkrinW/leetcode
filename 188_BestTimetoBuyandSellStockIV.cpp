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
    int maxProfit(int k, std::vector<int>& prices) {
        int n = prices.size();
        std::vector<int> buy(k);
        std::vector<int> sell(k);
        for (int i = 0; i < k; ++i) {
            buy[i] = -prices[0];
            sell[i] = 0;
        }
        for (int i = 1; i < n; ++i) {
            buy[0] = buy[0] > -prices[i] ? buy[0] : -prices[i];
            sell[0] = sell[0] > buy[0] + prices[i] ? sell[0] : buy[0] + prices[i];
            for (int j = 1; j < k; ++j) {
                buy[j] = buy[j] > sell[j-1] - prices[i] ? buy[j] : sell[j-1] - prices[i];
                sell[j] = sell[j] > buy[j] + prices[i] ? sell[j] : buy[j] + prices[i];
            }
        }
        return sell[k-1];
    }
};

int main() {
    return 0;
}