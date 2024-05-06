#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string s = "()[]{}";
    int num = s.size();
    std::stack<char> st;
    bool flag = true;
    for (int i = 0; i < num; ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else {
            if (st.empty()) {
                flag = false;
                break;
            } else if (s[i] - st.top() > 2 || s[i] < st.top()) {
                flag = false;
                break;
            } else {
                st.pop();
            }
        }
    }
    if (!st.empty()) {
        flag = false;
    }
    return flag;

}