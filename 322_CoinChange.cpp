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
    int coinChange(std::vector<int>& coins, int amount) {
        int *sumnum = new int[amount+1];
        sumnum[0] = 0;
        int coinum = coins.size();
        for (int i = 1; i < amount+1; ++i) {
            sumnum[i] = 1e6;
            for (int j = 0; j < coinum; ++j) {
                if (i-coins[j]>=0) {
                    int tmp = sumnum[i-coins[j]] + 1;
                    sumnum[i] = sumnum[i] < tmp ? sumnum[i] : tmp;
                } 
            }
        }
        if (sumnum[amount] == 1e6) {
            return -1;
        }
        return sumnum[amount];
    }
};

int main() {
    return 0;
}