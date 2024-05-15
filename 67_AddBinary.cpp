#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string sum = "";
        bool carry = false; //进位
        if (a.size() < b.size()) {
            sum = a;
            a = b;
            b = sum;
        }
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0) {
            if (j >= 0) {
                if (carry) {
                    if (a[i] == '0' && b[j] == '0') {
                        carry = false;
                    }
                    if (a[i] == b[j]) {
                        a[i] = '1';
                    } else {
                        a[i] = '0';
                    }
                } else {
                    if (a[i] == '1' && b[j] == '1') {
                        carry = true;
                    }
                    if (a[i] == b[j]) {
                        a[i] = '0';
                    } else {
                        a[i] = '1';
                    }
                }
                --i;
                --j;
            } else {
                if (carry && a[i] == '1') {
                    a[i] = '0';
                } else if (carry || a[i] == '1') {
                    carry = false;
                    a[i] = '1';
                } else {
                    carry = false;
                }
                --i;
            }
        }
        if (carry) {
            a = '1' + a;
        }
        return a;
    }
};

int main() {
    return 0;
}