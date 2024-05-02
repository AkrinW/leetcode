#include <iostream>
#include <string>

int main() {
    std::string s = "axc";
    std::string t = "ahbgxdc";
    int num1 = s.size();
    int num2 = t.size();
    int i = 0;
    int j = 0;
    if (num1 > num2) {
        return false;
    }
    while (i < num1 && j < num2) {
        if (s[i] == t[j]) {
            ++i;
        }
        ++j;
    }
    std::cout << (i == num1);
    return 0;

}