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
    int maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters, std::vector<int>& score) {
        int n = letters.size();
        int letter[26]{0};
        for (int i = 0; i < n; ++i) {
            ++letter[letters[i]-'a'];
        }
        n = words.size();
        int max = 0;
        int sum = 0;
        std::function <void(int)> dfs = [&] (int i) {
            if (i == n) {
                return;
            }
            for (int j = i; j < n; ++j) {
                int tmp = 0;
                int let[26]{0};
                bool flag = true;
                for (auto w : words[j]) {
                    ++let[w-'a'];
                    tmp += score[w-'a'];
                    if (let[w-'a'] > letter[w-'a']) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    for (int k = 0; k < 26; ++k) {
                        letter[k] -= let[k];
                    }
                    sum += tmp;
                    max = max > sum ? max : sum;
                }
                dfs(j+1);
                if (flag) {
                    sum -= tmp;
                    for (int k = 0; k < 26; ++k) {
                        letter[k] += let[k];
                    }
                }
            }
        };
        dfs(0);
        return max;
    }
};

int main() {
    std::vector<std::string> words{"dog","cat","dad","good"};
    std::vector<char> letters{'a','a','c','d','d','d','g','o','o'};
    std::vector<int> score{1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    Solution sol;
    sol.maxScoreWords(words,letters,score);
    return 0;
}