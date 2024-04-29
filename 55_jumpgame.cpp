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

    // only get 0 point cant move on;
    // store a num that means max num before
    // if it <= i which price[i] = 0; return false.
    //O(N)
    int max = 0;
    bool flag = true;
    int i = 0;
    while (max < prices.size()-1 && i < prices.size() - 1) {
        max = prices[i] + i > max ? prices[i] + i : max;
        if (prices[i] == 0 && max <= i) {
            flag = false;
            break;
        }
        ++i;
    }
    std::cout << flag;

    return 0;
}