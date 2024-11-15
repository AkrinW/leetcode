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
#include <thread>
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

class FizzBuzz {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv1, cv2, cv3, cv4;
    int flag = 0;
public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for (int i = 1; i <= n/3 - n/15; ++i) {
            std::unique_lock<mutex> lock(mtx);
            cv2.wait(lock,[this]{return flag == 1;});
            printFizz();
            flag = 0;
            cv1.notify_one();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for (int i = 1; i <= n/5 - n/15; ++i) {
            std::unique_lock<mutex> lock(mtx);
            cv3.wait(lock, [this]{return flag == 2;});
            printBuzz();
            flag = 0;
            cv1.notify_one();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for (int i = 1; i <= n/15; ++i) {
            std::unique_lock<mutex> lock(mtx);
            cv4.wait(lock, [this]{return flag == 3;});
            printFizzBuzz();
            flag = 0;
            cv1.notify_one();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (int i = 1; i <= n; ++i) {
            std::unique_lock<std::mutex> lock(mtx);
            cv1.wait(lock, [this]{return flag == 0;});
            if (i % 15 == 0) {
                flag = 3;
                cv4.notify_one();
            } else if (i % 3 == 0) {
                flag = 1;
                cv2.notify_one();
            } else if (i % 5 == 0){
                flag = 2;
                cv3.notify_one();
            } else {
                printNumber(i);
            }
        }
    }
};

void printFizz() {
    cout << "fizz ";
}

void printBuzz() {
    cout << "buzz ";
}

void printFizzBuzz() {
    cout << "fizzbuzz ";
}

void printNumber(int num) {
    cout << num << " ";
}

int main() {
    FizzBuzz fb(20);

    // 创建并启动线程
    thread t1(&FizzBuzz::fizz, &fb, printFizz);        // 用于打印 "fizz"
    thread t2(&FizzBuzz::buzz, &fb, printBuzz);        // 用于打印 "buzz"
    thread t3(&FizzBuzz::fizzbuzz, &fb, printFizzBuzz); // 用于打印 "fizzbuzz"
    thread t4(&FizzBuzz::number, &fb, printNumber);    // 用于打印数字

    // 等待所有线程执行完成
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    cout << endl;

    return 0;
}