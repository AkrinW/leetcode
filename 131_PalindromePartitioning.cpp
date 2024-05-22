#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <array>
#include <cctype>
#include <functional>

class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        int n = s.size();
        std::vector<std::vector<std::string>> part;
        std::vector<std::vector<int>> subp;
        std::map<std::pair<int,int>, int> mapp;
        for (int i = 0; i < n;++i) {
            int p = i, q = i + 1;
            while (p >= 0 && q <= n-1 && s[p] == s[q]) {
                ++mapp[{p,q}];
                --p;
                ++q;
            }
            p = i;
            q = i;
            while ( p >= 0 && q <= n-1 && s[p] == s[q]) {
                ++mapp[{p,q}];
                --p;
                ++q;
            }
        }
        std::vector<std::string> path;
        // std::sort(subp.begin(),subp.end());
        std::function <void(int)> dfs = [&](int i) {
            if (i == n) {
                part.push_back(path);
                return;
            }
            for (int j = i; j < n; ++j) {
                // auto it = std::find(subp.begin(),subp.end(),{i,j});
                if (mapp.count({i,j})) {
                    path.push_back(s.substr(i,j-i+1));
                    dfs(j+1);
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return part;
    }
};

int main() {
    Solution sol;
    sol.partition("efe");
    return 0;
}