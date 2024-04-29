//

#include <iostream>
#include <vector>

int main() {
    std::vector<int> prices(5);
    prices[0] = 3;
    prices[1] = 0;
    prices[2] = 6;
    prices[3] = 1;
    prices[4] = 5;
    // prices[5] = 4;
    int i;;
    int sum = prices.size();
    int Hindex[1001] = {0};
        for (i = 0; i <= 1001;++i) {
        Hindex[i] = 0;
    }
    for (i = 0; i < prices.size(); ++i) {
        ++Hindex[citations[i]];
    }
    for (i = 1000; i >= 0 ; --i) {
        sum += Hindex[i];
        if (sum >=i) {
            return i;
        }
    }
    return i;
    
}