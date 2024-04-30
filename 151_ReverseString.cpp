#include <iostream>
#include <stack>

int main() {
    std::string s1 = "ske is bule";
    std::string s2 = "";
    int n = s1.length();
    std::stack<char> s;
    int flag = 0;
    for (int i = n-1; i >= 0; --i) {
        if (s1[i] != ' ') {
            flag = 1;
            s.push(s1[i]);
        } else if (!s.empty()) {
            while (!s.empty()) {
                s2 += s.top();
                s.pop();
            }
            s2 += " ";
        }
    }
    if (s.empty()) {
        s2.erase(s2.size()-1);
    } else {
        while (!s.empty()) {
            s2 += s.top();
            s.pop();
        }
    }
    std::cout <<s2;


    return 0;
}