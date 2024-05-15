#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

class MedianFinder {
private:
    // priority_queue<int, vector<int>, less<int>> queMin;
    // priority_queue<int, vector<int>, greater<int>> queMax;
    std::priority_queue<int> queleft;
    std::priority_queue<int, std::vector<int>, std::greater<int>> queright;
    int lmr; //left - right

public:
    MedianFinder() {
        queleft.push(-1e6);
        queright.push(1e6);
        lmr = 0;
    }
    
    void addNum(int num) {
        if (num < queleft.top()) {
            if (lmr == 1) {
                queright.push(queleft.top());
                queleft.pop();
                --lmr;
            } else {
                ++lmr;
            }
            queleft.push(num);
        } else if (num > queright.top()) {
            if (lmr == -1) {
                queleft.push(queright.top());
                queright.pop();
                ++lmr;
            } else {
                --lmr;
            }
            queright.push(num);
        } else {
            if (lmr == 1) {
                queright.push(num);
                --lmr;
            } else {
                queleft.push(num);
                ++lmr;
            }
        }
    }
    
    double findMedian() {
        double find;
        if (lmr == 1) {
            find = queleft.top();
        } else if (lmr == -1) {
            find = queright.top();
        } else {
            find = (double(queleft.top()) + double(queright.top())) / 2;
        }
        return find;
    }
};

int main() {
    MedianFinder med;
    med.addNum(1);
    med.addNum(2);
    std::cout << med.findMedian();
    return 0;
}