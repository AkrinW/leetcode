#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::string s = "anagram", t = "nagaram";
    bool flag = true;
    int num = s.size();
    if (t.size() != num) {
        flag = false;
        return flag;
    }
    std::unordered_map<char, int> map;
    for (int i = 0; i < num; ++i) {
        ++map[s[i]];
    }
    for (int i = 0; i < num; ++i) {
        --map[t[i]];
        if (map[t[i]] < 0) {
            flag = false;
            break;
        }
    }
    std::cout << flag;

    return 0;
}