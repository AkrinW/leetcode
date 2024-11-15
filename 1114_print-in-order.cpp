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

class Foo {
private:
    std::mutex m2, m3;
public:
    Foo() {
        m2.lock();
        m3.lock();
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m2.unlock();
    }

    void second(function<void()> printSecond) {
        m2.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m2.unlock();
        m3.unlock();
    }

    void third(function<void()> printThird) {
        m3.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        m3.unlock();
    }
};
// 这段代码能够 AC，但实际上这种使用 mutex 的方法是 错误的，
// 因为根据 C++ 标准，在一个线程尝试对一个 mutex 对象进行 unlock 操作时，
// mutex 对象的所有权必须在这个线程上；也就是说，应该 由同一个线程来对一个
//  mutex 对象进行 lock 和 unlock 操作，否则会产生未定义行为。

// 用条件变量 实现RAII
class Foo {
private:
    std::mutex m2, m3;
    std::condition_variable cv2, cv3;
    // cv可以同时阻塞多个线程
    bool firstDone = false, secondDone = false;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstDone = true;
        cv2.notify_one();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(m2);
        cv2.wait(lock, [this]{return firstDone;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secondDone = true;
        cv3.notify_one();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lock(m3);
        cv3.wait(lock, [this]{return secondDone;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};



int main() {
    return 0;
}