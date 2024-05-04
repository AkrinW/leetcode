#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

int main() {
    std::string s[2] = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};

    std::vector<std::string> strs(s,s+2);
    std::vector<std::vector<std::string>> grop;
    int num = strs.size();
    std::vector<int*> map;
    for (int i = 0; i < num; ++i) {
        int n = strs[i].size();
        int *mult = new int[26];
        for (int j = 0; j < 26; ++j) {
            mult[j] = 0;
        }
        for (int j = 0; j < n; ++j) {
            ++mult[strs[i][j]-'a'];
        }
        map.push_back(mult);
    }
    std::vector<int> sub;
    int count = 0;
    for (int i = 0; i < num; ++i) {
        int j = 0;
        for (j = 0; j < count; ++j) {
            bool flag = true;
            for (int k = 0; k < 26;++k) {
                if (map[i][k] != map[sub[j]][k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        if (j == count) {
            std::vector<std::string> tmp;
            tmp.push_back(strs[i]);
            grop.push_back(tmp);
            sub.push_back(i);
            ++count;
        } else {
            grop[j].push_back(strs[i]);
        }
    }

    // std::unordered_map<char, int> *map = new std::unordered_map<char, int>[num];
    // for (int i = 0; i < num; ++i) {
    //     int n = strs[i].size();
    //     for (int j = 0; j < n; ++j) {
    //         ++map[i][strs[i][j]];
    //     }
    // }
    // std::vector<int> sub;
    // for (int i = 0; i < num; ++i) {
    //     int j = 0;
    //     for (j = 0; j < sub.size(); ++j) {
    //         if (strs[i].size() != strs[sub[j]].size()){
    //             continue;
    //         }
    //         bool flag = true;
    //         for (char k = 'a'; k < 'z' + 1; ++k) {
    //             if (map[i][k] != map[sub[j]][k]) {
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //         if (flag) {
    //             break;
    //         }
    //     }
    //     if (j == sub.size()) {
    //         std::vector<std::string> tmp;
    //         tmp.push_back(strs[i]);
    //         grop.push_back(tmp);
    //         sub.push_back(i);
    //     } else {
    //         grop[j].push_back(strs[i]);
    //     }
    // }

    return 0;
}