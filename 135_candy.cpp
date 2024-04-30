#include <iostream>
#include <vector>
// traverse 2 times O(N)
// compare the left traverse and right traverse, count the bigger one
int main() {
    int a[7] = {1,2,85,85,85,2,1};
    std::vector<int> ratings(a,a+7);
    int n = ratings.size();
    int count = 0;
    std::vector<int> left(n);
    left[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i-1]) {
            left[i] = left[i-1] + 1;
        } else {
            left[i] = 1;
        }
    }
    count = left[n-1];
    int tmp = 1;
    for (int i = n-2; i >= 0; --i) {
        if (ratings[i] > ratings[i+1]) {
            ++tmp;
        } else {
            tmp = 1;
        }
        count += std::max(tmp, left[i]);
    }
    std::cout <<count;
    return 0;
}