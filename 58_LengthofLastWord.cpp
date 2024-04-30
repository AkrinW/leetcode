#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int len = s.length()-1;
        int num = 0;
        int count = 0;
        while (count == 0) {
            if (s[len] == ' ') {
                --len;
            } else {count = 1;}
        }
        while (count) {
            if (len < 0) {return num;}
            if (s[len] != ' ') {
                ++num;
                --len;
            } else {count = 0;}
        }
        return num;
    }
};