#include <iostream>
#include <string>
#include <vector>
using namespace std;

int strStr(string& s1, string& s2) {
    for (int i = 0; i <= int(s1.length()-s2.length()); ++i) {
        int j = 0;
        for (j = 0; j < s2.length(); ++j) {
            if (s1[i+j] != s2[j]) {
                break;
            }
        }
        if (j == s2.length()) {
            return i;
        }
    }
    return -1;
}

vector<int> getNext(string& s) {
    vector<int> next(s.length(),0);
    int i = 1;
    int j = 0;
    while (i < s.length()) {
        if (s[i] == s[j]) {
            ++j;
            next[i] = j;
            ++i;
        } else if (j == 0) {
            next[i] = j;
            ++i;
        } else {
            j = next[j-1];
        }
        }
    return next;
}

int strStr_KMP(string& s1, string& s2) {
    vector<int> next = getNext(s2);
    int i = 0, j = 0;
    while (i <= s1.length()) {
        if (s1[i] == s2[j]) {
            ++i;
            ++j;
        } else {
            if (j == 0) {
                ++i;
            } else {
                j = next[j-1];
            }
        }
        if (j == s2.length()) {
            return i-j;
        }
    }
    return -1;
}

int main() {
    string text = "aabaaabaaacadcadde";
    string pattern = "adcadde";
                 //   0001200
    // int pos = strStr(text, pattern);
    int pos = strStr_KMP(text, pattern);

    if (pos != -1) {
        cout << "Pattern found at:" << pos <<endl;
    } else {
        cout << "Pattern not found." << endl;
    }
    return 0;
}