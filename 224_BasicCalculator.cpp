#include <iostream>
#include <string>
#include <stack>
//先构建波兰表达式，再进行计算
int main() {
    std::string s ="2-4-(8+2-6+(8+4-(1)+8-10))";
    int num = s.size();
    std::stack<char> st1;
    std::stack<int> st2;
    int i = 0;
    bool flag = false;
    while (i < num) {
        switch(s[i]) {
            case '(':
                st1.push(s[i]);
                flag = true;
                ++i;
                break;
            case ')':
                while (st1.top() != '(') {
                    int tmp = st2.top();
                    st2.pop();
                    if (st1.top() == '+') {
                        tmp = st2.top() + tmp;
                    } else {
                        tmp = st2.top() - tmp;
                    }
                    st2.pop();
                    st2.push(tmp);
                    st1.pop();
                }
                st1.pop();
                ++i;
                break;
            case '+':
                if (!st1.empty() && st1.top() == '-') {
                    int tmp = st2.top();
                    st2.pop();
                    tmp = st2.top() - tmp;
                    st2.pop();
                    st2.push(tmp);
                    st1.pop();
                }
                if (!st1.empty() && st1.top() == '+') {
                    int tmp = st2.top();
                    st2.pop();
                    tmp = st2.top() + tmp;
                    st2.pop();
                    st2.push(tmp);
                    st1.pop();
                }
                st1.push(s[i]);
                ++i;
                break;
            case '-':
                if (st2.empty() || flag) {
                    st2.push(0);
                }
                if (!st1.empty() && st1.top() == '+') {
                    int tmp = st2.top();
                    st2.pop();
                    tmp = st2.top() + tmp;
                    st2.pop();
                    st2.push(tmp);
                    st1.pop();
                }
                if (!st1.empty() && st1.top() == '-') {
                    int tmp = st2.top();
                    st2.pop();
                    tmp = st2.top() - tmp;
                    st2.pop();
                    st2.push(tmp);
                    st1.pop();
                }
                st1.push(s[i]);
                ++i;
                break;
            case ' ':
                ++i;
                break;
            default:
                int j = i;
                while (i < num && s[i] >= '0' && s[i] <= '9') {
                    ++i;
                }
                std::string tmp = s.substr(j, i-j);
                st2.push(std::stoi(tmp));
                flag = false;
                break;
        }
    }
    while (!st1.empty()) {
        if (st1.top() == '+') {
            int tmp = st2.top();
            st2.pop();
            tmp = st2.top() + tmp;
            st2.pop();
            st2.push(tmp);
        } else {
            int tmp = st2.top();
            st2.pop();
            tmp = st2.top() - tmp;
            st2.pop();
            st2.push(tmp);
        }
        st1.pop();
    }
    std::cout << st2.top();
    return 0;
}