#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>

class Solution {
private:
    bool CanMutation(std::string a, std::string b) {
        int len = a.size();
        bool flag;
        int count = 0;
        for (int i = 0; i < len; ++i) {
            if (a[i] != b[i]) {
                ++count;
            }
            if (count > 1) {
                break;
            }
        }
        if (count == 1) {
            flag = true;
        }  else {
            flag = false;
        }
        return flag;
    }
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_map<int, int> map;
        std::queue<int> que;
        int num = wordList.size();
        int len = beginWord.size();
        map[-1] = 1;
        bool flag = true;
        for (int i = 0; i < num; ++i) {
            map[i] = num + 3; 
            if (wordList[i] == endWord) {
                flag = false;
            }
        }
        if (flag) {
            return 0;
        }
        que.push(-1);
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            int step = map[now];
            std::string s1;
            if (now == -1) {
                s1 = beginWord;
            } else {
                s1 = wordList[now];
            }
            for (int i = 0; i < num; ++i) {
                if (map[i] > (step+1)) {
                    std::string s2 = wordList[i];
                    if (CanMutation(s1,s2)) {
                        map[i] = step + 1;
                        que.push(i);
                        if (s2 == endWord) {
                            return map[i];
                        }
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    std::string startgene = "AACCGGTT";
    std::string endgene = "AAACGGTA";
    std::vector<std::string> bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    Solution sol;
    int a = sol.ladderLength(startgene,endgene,bank);

    return 0;
}