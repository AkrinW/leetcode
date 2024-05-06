#include <iostream>
#include <string>
#include <vector>
#include <stack>

int main() {
    std::vector<std::string> tokens = {"2","1","+","3","*"};
    int num = tokens.size();
    std::stack<int> st;
    for (int i = 0; i < num; ++i) {
        if (tokens[i] == "+") {
            int tmp = st.top();
            st.pop();
            tmp = st.top() + tmp;
            st.pop();
            st.push(tmp);
        } else if (tokens[i] == "-") {
            int tmp = st.top();
            st.pop();
            tmp = st.top() - tmp;
            st.pop();
            st.push(tmp);
        } else if (tokens[i] == "*") {
            int tmp = st.top();
            st.pop();
            tmp = st.top() * tmp;
            st.pop();
            st.push(tmp);
        } else if (tokens[i] == "/") {
            int tmp = st.top();
            st.pop();
            tmp = st.top() / tmp;
            st.pop();
            st.push(tmp);
        } else {
            int tmp = std::stoi(tokens[i]);
            st.push(tmp);
        }
    }
    std::cout << st.top();


    return 0;
}