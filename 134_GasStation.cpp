//use two pointers simulate the car's start and end
//if cal form start to end > 0, add end; else add start;
//if start == end , prove that cannot start before this place.add start and end.
//if start == size, return -1;
//O(N)

//recommend that since one station cant arrive, from start to end all station
//cant arrive that station.
#include <iostream>
#include <vector>

int main() {
    int a[5] = {5,1,2,3,4};
    int b[5] = {4,4,1,5,1};
    std::vector<int> gas(a, a+5); 
    std::vector<int> cost(b, b+5); 
    int n = gas.size();
    int count = 0;

    int i = 0, j = 0;
    count += gas[i];
    while (true) {
        if (count >= cost[j]) {
            count -= cost[j];
            ++j;
            if (j == n) {
                j = 0;
            }
            if (j == i) {
                std::cout <<i;
                return i;
            }
            count += gas[j];
        } else {
            if (i == j) {
                count -= gas[i];
                ++i;
                ++j;
                if (i == n) {
                    std::cout << -1;
                    return -1;
                }
                count += gas[i];
            } else {
                count += cost[i];
                count -= gas[i];
                ++i;
            }
        }
    }
    return 0;
}