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
    int longestAwesome(std::string s) {
        int n = s.size();
        // int num[10] = {1,2,4,8,16,32,64,128,256,512};
        // std::unordered_map<int,int> map;
        std::vector<int> map(1025,n);
        map[0] = -1;
        int ans = 0;
        int longest = 0;
        for (int i = 0; i < n; ++i) {
            ans ^= 1 << (s[i]-'0');
            if (map[ans] == n) {
                map[ans] = i;
            } else if (i - map[ans] > longest) {
                longest = i - map[ans];
            }
            for (int j = 0; j < 10; ++j) {
                int tmp = ans ^ (1 << j);
                if (i - map[tmp] > longest) {
                    longest = i - map[tmp];
                }
            }
        }
        return longest;
    }
};

int main() {
    return 0;
}