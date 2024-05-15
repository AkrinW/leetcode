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
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        int len = s.size();
        int num = wordDict.size();
        int *wordlen = new int[num];
        int wordnum = 0;
        std::unordered_map<std::string, int> map;
        std::unordered_map<int,int> wordlmap;
        for (int i = 0; i < num; ++i) {
            ++map[wordDict[i]];
            int tmp = wordDict[i].size();
            if (!wordlmap.count(tmp)) {
                ++wordlmap[tmp];
                wordlen[wordnum] = tmp;
                ++wordnum;
            }
        }
        bool *flag = new bool[len];
        for (int i = 0; i < len; ++i) {
            flag[i] = false;
            for (int j = 0; j < wordnum; ++j) {
                if ((i-wordlen[j] >= 0 && flag[i-wordlen[j]]) || (i-wordlen[j] == -1)) {
                    std::string tmp = s.substr(i-wordlen[j]+1,wordlen[j]);
                    if (map.count(tmp)) {
                        flag[i] = true;
                        break;
                    }
                }
            }
        }
        return flag[len-1];
    }
};

int main() {
    std::string s = "applepenapple";
    std::vector<std::string> wordD = {"apple","pen"};
    Solution sol;
    sol.wordBreak(s,wordD);
    return 0;
}