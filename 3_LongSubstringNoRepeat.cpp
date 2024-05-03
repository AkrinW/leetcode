#include <iostream>
#include <string>

int main() {
    std::string s = "abcabcbb";
    int max = 0, head = 0, tail = 0;
    int map[128];
    std::fill(std::begin(map),std::end(map),-1);
    while (tail < s.length()) {
        if (map[s[tail]] >= head) {
            max = std::max(max,tail-head);
            head = map[s[tail]] + 1;
        }
        map[s[tail]] = tail;
        ++tail;
    }
    max = std::max(max,tail-head);


    return 0;
}