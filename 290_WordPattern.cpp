#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::string pattern = "aaaa", s = "dog cat cat dog";
    bool flag = true;
    int nump = pattern.size();
    int nums = s.size();
    std::unordered_map<char, std::string> map1;
    std::unordered_map<std::string, char> map2;
    int i = 0;// s' subscript
    for (int k = 0; k < nump; ++k) {
        if (i == nums) {
            flag = false;
            break;
        }
        if (s[i] == ' ') {
            ++i;
        }
        std::string tmp = "";
        while (i != nums && s[i] != ' ') {
            tmp += s[i];
            ++i;
        }
        if (map1.count(pattern[k])) {
            if (map1[pattern[k]] != tmp) {
                flag = false;
                break;
            }
        } else {
            if (map2.count(tmp)) {
                flag = false;
                break;
            } else {
                map1[pattern[k]] = tmp;
                map2[tmp] = pattern[k];
            }
        }
    }
    if (i != nums) {
        flag = false;
    }
    std::cout << flag;




    return 0;
}