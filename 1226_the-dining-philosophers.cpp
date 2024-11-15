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

class Solution {
public:

};

class DiningPhilosophers {
private:
    std::mutex mtx;
    std::condition_variable cv;
    bool fork[5] = {true, true, true, true, true};
public:
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        std::unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]{return fork[philosopher] && fork[(philosopher+1) % 5];});
        fork[philosopher] = false;
        pickLeftFork();
        fork[(philosopher+1)%5] = false; 
        pickRightFork();
        eat();
        fork[philosopher] = true;
        putLeftFork();
        fork[(philosopher+1) % 5] = true;
        putRightFork();
        cv.notify_all();
    }
};


int main() {
    return 0;
}