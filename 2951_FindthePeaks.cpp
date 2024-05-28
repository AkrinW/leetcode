#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <array>
#include <cctype>
#include <functional>
using namespace std;

//优化cin 和cout 速度
auto __FAST__IO__ = []() noexcept -> int {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    return 0;
}();

class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        int n = mountain.size();
        int i = 1;
        int flag = 0;
        std::vector<int> find;
        while (i < n-1) {
            if (flag == 0) {
                if (mountain[i] > mountain[i+1]) {
                    if (mountain[i] > mountain[i-1]) {
                        find.push_back(i);
                    }
                    i += 2;
                } else if (mountain[i] == mountain[i+1]) {
                    i += 2;
                } else {
                    ++i;
                    flag = 1;
                }
            } else {
                if (mountain[i] > mountain[i+1]) {
                    find.push_back(i);
                    i +=2;
                    flag = 0;
                } else if (mountain[i] == mountain[i+1]) {
                    i +=2;
                    flag = 0;
                } else {
                    ++i;
                }
            }
        }
        return find;
    }

};

int main() {
    return 0;
}