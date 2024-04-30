
#include <iostream>
#include <string>
int main() {
    int num = 2;
    switch (num) {
        case 1:
            std::cout << "Number is 1" << std::endl;
        case 2:
            std::cout << "Number is 2" << std::endl;
        case 3:
            std::cout << "Number is 3" << std::endl;
            break;
        default:
            std::cout << "Number is not 1, 2, or 3" << std::endl;
    }
    return 0;
}

class Solution {
public:
    int romanToInt(std::string s) {
        int answer = 0;
        int s1[s.length()];
        int i = 0;
        for (i = 0; i < s.length(); ++i) {
            switch (s[i]) {
                case 'I': s1[i] = 1; break;
                case 'V': s1[i] = 5; break;
                case 'X': s1[i] = 10; break;
                case 'L': s1[i] = 50; break;
                case 'C': s1[i] = 100; break;
                case 'D': s1[i] = 500; break;
                case 'M': s1[i] = 1000; break;
            }
        }
        for (i = 0; i < s.length()-1; ++i) {
            if (s1[i] < s1[i+1]) {
                answer = answer + s1[i+1] - s1[i];
                i = i + 1;
            } else {
                answer = answer + s1[i];
            }
        }
        if (i == s.length()-1) {
            answer = answer + s1[s.length()-1];
        }
        return answer;
    }
};