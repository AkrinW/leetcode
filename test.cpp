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

int main() {
    return 0;
}
// isdigit
// std::array<int, 5> ar;
// double density(double, double);


//         function<int(int, int, int)> dfs = [&](int x, int fa, int sum) -> int {
//             int cnt = sum % signalSpeed == 0;
//             for (auto &[y, wt] : g[x]) {
//                 if (y != fa) {
//                     cnt += dfs(y, x, sum + wt);
//                 }
//             }
//             return cnt;
//         };


// using namespace std;

// struct A {
//     A a;
// };

// struct B {
//     C c;
// };

// struct C {
//     B b;
// };

// union a {
//     int a_num;
//     std::string a_string;
// };

// // anonymous union
// struct A {
//     union {
//         int num;
//         std::string str;
//     };
// };

// enum {
//     red,orange,yellow,green,blue,violet
// };


// int main() {
//     cout << 1 << endl;
//     int p[6] {0,0};
//     double c = density()
//     return 0;
// }
