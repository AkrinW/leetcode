#include <iostream>
#include <vector>

int main() {
    int a[4] = {2,7,11,15};
    std::vector<int> numbers(a,a+4);
    int target = 9;
    int nums = numbers.size();
    std::vector<int> two;
    int i = 0;
    int j = nums-1;
    int tmp = 0;
    while (i < j) {
        tmp = numbers[i] + numbers[j];
        if (tmp > target) {
            --j;
        } else if (tmp < target) {
            ++i;
        } else {
            break;
        }
    }
    two.push_back(numbers[i]);
    two.push_back(numbers[j]);
    std::cout << two[0] << two[1];

    return 0;
}