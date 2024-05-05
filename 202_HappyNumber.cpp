#include <iostream>
#include <set>

int n_next(int n) {
    int next = 0;
    while (n > 0) {
        next += (n % 10) * (n % 10);
        n /= 10;
    }
    return next;
}
int main() {
    int n = 19;
    int a[8] = {4,16,37,58,89,145,42,20};
    std::set<int> map(a,a+8);
    while (n != 1 && !map.count(n)) {
        n = n_next(n);
    }
    bool flag = false;
    if (n == 1) {
        flag = true;
    }
    std::cout << flag;
    return 0;
}