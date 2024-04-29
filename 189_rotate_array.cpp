#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    std::vector<int> nums(4);
    nums[0] = -1;
    nums[1] = -100;
    nums[2] = 3;
    nums[3] = 99;
    int n = nums.size();
    int k = 2;
    int count = 2;
    // int count = std::gcd(k, n);
    int tmp;
    if (n == 1) {
        return 0;
    }
    while (k >= n) {
        k -= n;
    }
    for (int i = 0; i < count; ++i) {
        int j = i;
        int c = j - k;
        tmp = nums[j];

        while (c != i) {
            if (c < 0) {
                c += n;
            }
            if (j < 0) {
                j += n;
            }
            nums[j] = nums[c];
            c -= k;
            j -= k;
        }
        if (j < 0) {
            j += n;
        }
        nums[j] = tmp;
    }
    return 0;
}