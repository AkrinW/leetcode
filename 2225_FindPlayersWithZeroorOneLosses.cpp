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
    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) {
        std::unordered_map<int, int> players;
        std::vector<std::vector<int>> find = {{},{}};
        for (auto match : matches) {
            if (!players.count(match[1]) || players[match[1]] == 0) {
                players[match[1]] = 1;
            } else if (players[match[1]] == 1) {
                players[match[1]] = 2;
            }
            if (!players.count(match[0])) {
                players[match[0]] = 0;
            }
        }
        for (auto player : players) {
            if (player.second == 0) {
                find[0].push_back(player.first);
            } else if (player.second == 1) {
                find[1].push_back(player.first);
            }
        }
        sort(find[0].begin(), find[0].end());
        sort(find[1].begin(), find[1].end());
        return find;
    }
};


int main() {
    return 0;
}