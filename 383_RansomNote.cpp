#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::string ransomNote = "ac", magazine = "aab";
    bool flag = true;
    std::unordered_map<char, int> map;
    int numr = ransomNote.size();
    int numm = magazine.size();
    if (numm < numr) {
        flag = false;
        return flag;
    }
    for (int i = 0; i < numm; ++i) {
        ++map[magazine[i]];
    }
    for (int i = 0; i < numr; ++i) {
        --map[ransomNote[i]];
        if (map[ransomNote[i]] < 0) {
            flag = false;
            break;
        }
    }
    std::cout << flag;


    return 0;
}