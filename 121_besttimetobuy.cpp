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
    //sperate list into small pieces.choose a smallest one as start, calc the max prices.
    //when meet a smaller one, change it and restart max prices. compare the max.
    //O(N)
    int i = 0;
    int buy = 0;
    int sell = 0;
    int max = 0;
    int tmp = 0;
    for (i = 0; i < prices.size(); ++i) {
        if (prices[i] < prices[buy]) {
            //new buy
            if (max < tmp) {
                max = tmp;
            }
            tmp = 0;
            buy = i;
            sell = i;
        } else if (prices[i] > prices[sell]) {
            sell = i;
            tmp = prices[sell] - prices[buy];
        }
    }
    if (max < tmp) {
        max = tmp;
    }
    std::cout << max << std::endl;
    return 0;
}