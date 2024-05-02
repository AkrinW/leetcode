#include <iostream>
#include <string>
// a-z 97-122 A-Z 65-90
int main() {
    std::string s = "0p";
    char c1, c2;
    int n = s.size();
    int i = 0, j = n-1;
    c1 = s[i];
    c2 = s[j];
    bool flag = true;
    while (flag) {
        if (i >= j) {
            break;
        }
        if (c1 >= 65 && c1 <= 90) {
            c1 += 32;
        } else if (c1 < 48 || (c1 > 57 && c1 < 97) || c1 > 122) {
            ++i;
            c1 = s[i];
            continue;
        }
        if (c2 >= 65 && c2 <= 90) {
            c2 += 32;
        } else if (c2 < 48 || (c2 > 57 && c2 < 97) || c2 > 122) {
            --j;
            c2 = s[j];
            continue;
        }        
        if (c1 == c2) {
            ++i;
            --j;
        } else {
            flag = false;
        }
        c1 = s[i];
        c2 = s[j];
    }
    std::cout << flag;



    return 0;
}