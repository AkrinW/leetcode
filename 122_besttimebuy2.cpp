//same as 121, need to consider the next day situation.
//in this time, need to sell as long as decrease 
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

    int max = 0;
    int buy = 0;
    int sell = 0;
    for (int i = 0; i < prices.size() ; ++i) {
        if (prices[i] > prices[sell]) {
            //in this time, need to renew sell;
            sell = i;
        } else if (prices[i] < prices[sell]) {
            max += prices[sell] - prices[buy];
            sell = i;
            buy = i;
        }
    }
    max += prices[sell] - prices[buy];
    std::cout << max;


    return 0;
}