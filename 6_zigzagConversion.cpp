#include <iostream>
#include <string>

int main() {
    std::string s = "PAYPALISHIRING";
    int numRows = 4;
    std::string s2 = "";
    int n = s.size();
    int i = 0;
    int p = i, q;
    if (numRows == 1) {
        std::cout << s;
        return 0;
    }
    while (p < n) {
        s2 += s[p];
        p += numRows*2-2;
    }
    for (i = 1; i < numRows-1; ++i) {
        p = i;
        q = numRows * 2 - 2 - p;
        while (true) {
            if (p >= n) {
                break;
            }
            s2 += s[p];
            p += numRows*2-2;
            if (q >= n) {
                break;
            }
            s2 += s[q];
            q += numRows*2-2;
        }
    }
    p = numRows -1;
    while (p < n) {
        s2 += s[p];
        p += numRows*2-2;
    }
    std::cout << s2;
    return 0;
}