// in this case, divide array into several intervals.
// intervals replace array's least steps.
//O(N)

#include <iostream>
#include <vector>

int main() {
    std::vector<int> prices(6);
    prices[0] = 7;
    prices[1] = 1;
    prices[2] = 5;
    prices[3] = 3;
    prices[4] = 6;
    prices[5] = 4;

    int count = 1;
    int farthest = 0;
    int i = 0;
    int far = 0;
    while (i <= farthest && farthest < prices.size()-1) {
        far = prices[i] + i > far ? prices[i] + i : far;
        if (far >= prices.size()-1) {
            std::cout << count;
            return count;
        }
        if (i == farthest) {
            ++count;
            farthest = far;
        }
        ++i;
    }
    std::cout << count;

    return 0;
}