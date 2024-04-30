#include <iostream>
#include <vector>
//2 traverse form left and form right.O(N)
//get the min one in two traverse.
//when meet a number bigger than the start, renew the pointer to it.
int main() {
    int a[6] = {4,2,0,3,2,5};
    std::vector<int> height(a,a+6);
    int n = height.size();
    std::vector<int> left(n);
    int tmp = height[0];
    left[0] = 0;
    for (int i = 1; i< n-1;++i) {
        if (height[i] <= tmp) {
            left[i] = tmp-height[i];
        } else{
            tmp = height[i];
            left[i] = 0;
        }
    }
    left[n-1] = 0;
    tmp = height[n-1];
    int count = 0;
    for (int i = n-2;i>0;--i) {
        if (height[i] > tmp) {
            tmp = height[i];
        }
        count += left[i] < tmp-height[i] ? left[i] : tmp-height[i];
    }
    std::cout <<count ;


    return 0;
}