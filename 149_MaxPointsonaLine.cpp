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
    int maxPoints(std::vector<std::vector<int>>& points) {
        int num = points.size();
        if (num < 3) {
            return num;
        }
        std::unordered_map<int,int> map;
        int max = 0;
        for (int i = 0; i < num; ++i) {
            ++map[points[i][0]];
            if (map[points[i][0]] > max) {
                ++max;
            }
        }
        for (int i = 0; i + max < num; ++i) {
            std::unordered_map<double,int> tmpmap;
            for (int j = 1; j < num; ++j) {
                if (points[j][0] != points[i][0]) {
                    double tmp = double((points[j][1]-points[i][1]))/double((points[j][0]-points[i][0]));
                    ++tmpmap[tmp];
                    if (tmpmap[tmp] + 1> max) {
                        ++max;
                    }
                }
            }
        }
        return max;
    }
};

int main() {
    std::vector<std::vector<int>> num = {{0,0},{4,5},{7,8},{8,9},{5,6},{3,4},{1,1}};
    Solution sol;
    std::cout <<sol.maxPoints(num);
    return 0;
}