#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::string s = "paper", t = "titll";
    bool flag = true;
    std::unordered_map<char, char> map1, map2;//2maps make mapping
    int num = s.size();

    for (int i = 0; i < num; ++i) { 
        if (map1.count(t[i])) {
            if (map1[t[i]] != s[i]) {
                flag = false;
                break;
            }
        } else {
            if (map2.count(s[i])) {
                flag = false;
                break;
            } else {
                map1[t[i]] = s[i];
                map2[s[i]] = t[i];
            }
        }
    }
    std::cout << flag;

    return 0;
}