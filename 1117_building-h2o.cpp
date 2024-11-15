#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <array>
#include <cctype>
#include <functional>
#include <ranges>
#include <mutex>
#include <condition_variable>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//优化cin 和cout 速度
auto __FAST__IO__ = []() noexcept -> int {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    return 0;
}();

class H2O {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int numH = 0, numO = 0;
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]{return numH < 2;});
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++numH;
        if (numH == 2 && numO == 1) {
            numH = 0;
            numO = 0;
            cv.notify_all();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[this]{return numO == 0;});
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        ++numO;
        if (numH == 2 && numO == 1) {
            numH = 0;
            numO = 0;
            cv.notify_all();
        }
    }
};


int main() {
    return 0;
}