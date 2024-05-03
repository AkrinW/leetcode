#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
//这题思路还是挺明确的，优化没想到
//主要还是熟悉哈希表的用法
//包括赋值与比较
int main() {
    std::string s = "aaaaaaaaaaaaaa";
    std::string s1[2] = {"aa","aa"};
    std::vector<std::string> words(s1,s1+2);
    int num1 = s.size();
    int num2 = words.size();
    int num3 = words[0].size();
    std::vector<int> find;
    std::unordered_map<std::string, int> hash;
    std::unordered_map<std::string, int> hash2;
    for (int i = 0; i < num2; ++i) {
        ++hash[words[i]];
    }
    std::string tmp = "";
    int m = 0;
    int n = 0;
    int count = 0;

    for (int i = 0; i < num3; ++i) {
        m = n = i;
        count = 0;
        hash2.clear();
        while (n + num3 <= num1) {
            tmp = s.substr(n, num3);
            if (hash.count(tmp)) {
                ++hash2[tmp];
                n += num3;
                ++count;
                while (hash2[tmp] > hash[tmp]) {
                    std::string tmp2 = s.substr(m,num3);
                    --hash2[tmp2];
                    --count;
                    m += num3;
                }
                if (count == num2) {
                    find.push_back(m);
                }
            } else {
                count = 0;
                n += num3;
                m = n;
                hash2.clear();
            }
        }
    }
    std::cout << find.size() << std::endl;
    for (int i = 0; i < find.size(); ++i) {
        std::cout << find[i] << ' ';
    }

    return 0;
}