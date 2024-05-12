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
        }
        if (count == 1) {
            flag = true;
        }  else {
            flag = false;
        }
        return flag;
    }
public:
    int minMutation(std::string startGene, std::string endGene, std::vector<std::string>& bank) {
        std::unordered_map<int, int> map;
        std::queue<int> que;
        int num = bank.size();
        int len = startGene.size();
        map[-1] = 0;
        for (int i = 0; i < num; ++i) {
            map[i] = num + 2; 
        }
        que.push(-1);
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            int step = map[now];
            std::string s1;
            if (now == -1) {
                s1 = startGene;
            } else {
                s1 = bank[now];
            }
            for (int i = 0; i < num; ++i) {
                std::string s2 = bank[i];
                if (map[i] > (step+1) && CanMutation(s1,s2)) {
                    map[i] = step + 1;
                    que.push(i);
                    if (s2 == endGene) {
                        return map[i];
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    std::string startgene = "AACCGGTT";
    std::string endgene = "AAACGGTA";
    std::vector<std::string> bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    Solution sol;
    int a = sol.minMutation(startgene,endgene,bank);

    return 0;
}