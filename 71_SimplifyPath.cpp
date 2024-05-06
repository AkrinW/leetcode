#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string path = "/home/";
    int n = path.size();
    std::string simple = "";
    std::stack<std::string> st;
    int i = n - 1, j = n - 1;
    while (path[i] == '/') {
        --i;
    }
    j = i;
    while (i >= 0) {
        while (path[i] != '/') {
            --i;
        }
        std::string tmp = path.substr(i + 1, j - i);
        if (tmp == "..") {
            st.push(tmp);
        } else if (tmp != ".") {
            if (st.empty() || st.top() != "..") {
                st.push(tmp);
            } else {
                st.pop();
            }
        }
        while ( path[i] == '/') {
            --i;
        }
        j = i;
    }
    while (!st.empty()) {
        if (st.top() != "..") {
            simple += '/';
            simple += st.top();
        }
        st.pop();
    }
    if (simple == "") {
        simple += '/';
    }
    std::cout << simple;

    return 0;
}