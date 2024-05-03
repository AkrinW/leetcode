#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string s = "ADOBECODEBANC";
    std::string t = "ABCF";
    std::unordered_map<char, int> hash1, hash2;
    std::string mins = "";
    int num1 = s.size();
    int num2 = t.size();
    if (num2 > num1) {
        return 0;
    }
    for (int i = 0; i < num2; ++i){
        ++hash1[t[i]];
    }
    int min = 1e5;
    int len = 0;
    int count = 0;//用于统计t里已经有多少个包含到的字符
    int i = 0;
    int j = 0;
    while (j < num1) {
        if (hash1.count(s[j])) {
            ++hash2[s[j]];
            if (hash2[s[j]] <= hash1[s[j]]) {
                ++count;
            }
            if (count == num2) {
                while(!hash1.count(s[i]) || hash2[s[i]] >= hash1[s[i]] + 1) {
                    if (hash1.count(s[i])) {
                        --hash2[s[i]];
                    }
                    ++i;
                }
                len = j - i + 1;
                if (len < min) {
                    min = len;
                    mins = s.substr(i, len);
                }
            }
        } 
        ++j;
    }
    std::cout << mins;



    return 0;
}