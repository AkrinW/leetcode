#include <iostream>
#include <vector>

int main() {
    int a[2] = {1,1};
    std::vector<int> height(a,a+2);
    int n = height.size();
    int i = 0;
    int j = n-1;
    int minside = height[i] < height[j] ? height[i] : height[j];
    int maxarea = (j - i) * minside;
    while (i != j) {
        if (minside == height[i]) {
            ++i;
        } else {
            --j;
        }
        minside = height[i] < height[j] ? height[i] : height[j];
        if (maxarea < (j-i) * minside) {
            maxarea = (j-i) * minside;
        }
    }
    std::cout << maxarea;
    return 0;
}