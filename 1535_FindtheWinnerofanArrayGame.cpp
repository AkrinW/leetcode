#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <array>
#include <cctype>

class Solution {
public:
    int getWinner(std::vector<int>& arr, int k) {
        int n = arr.size();
        int win_time = 0;
        int winner = arr[0];
        if (k == 1) {
            return arr[0] > arr[1] ? arr[0] : arr[1];
        }
        for (int i = 1; i < n; ++i) {
            if (winner > arr[i]) {
                ++win_time;
                if (win_time == k) {
                    break;
                }
            } else {
                winner = arr[i];
                win_time = 1;
            }
        }
        return winner;
    }
};

int main() {
    return 0;
}