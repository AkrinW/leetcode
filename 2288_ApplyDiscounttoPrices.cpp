#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <array>
#include <cctype>
#include <functional>
#include <ranges>
#include <format>
#include <iomanip>
using namespace std;


//优化cin 和cout 速度
auto __FAST__IO__ = []() noexcept -> int {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    return 0;
}();

class Solution {

private:
    std::string to_string_with_precision(double value, int n = 2) {
        std::ostringstream out;
        out << std::fixed << std::setprecision(n) << value;
        return out.str();
    }
public:
    string discountPrices(string sentence, int discount) {
        string sent = "";
        int n = sentence.size();
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (sentence[i] != '$') {
            } else {
                if (i != 0 && sentence[i-1] != ' ') {
                    continue;
                }
                ++i;
                sent += sentence.substr(j, i - j);
                j = i;
                while (i < n && sentence[i] >= '0' && sentence[i] <= '9') {
                    ++i;
                }
                if (i == j || (i != n && sentence[i] != ' ')) {
                    continue;
                }
                double tmp = std::stod(sentence.substr(j, i - j));
                if (tmp == 0) {
                    sent += '0';
                } else {
                    tmp = (100 - discount) * tmp / 100;
                    std::string result = to_string_with_precision(tmp);
                    sent += result;
                }
                j = i;
            }
        }
        if (j != n) {
            sent += sentence.substr(j, n-j);
        }
        return sent;
    }
};
int main() {
    Solution sol;
    sol.discountPrices("1 2 $3 4 $5 $6 7 8$ $9 $10$",100);
    return 0;
}