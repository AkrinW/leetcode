#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> com;
        std::stack<int> st;
        st.push(1);
        int count = 1;
        std::vector<int> tmp;
        tmp.push_back(1);
        while (!st.empty()) {
            int t = st.top();
            if (count < k && t < n) {
                st.push(t+1);
                tmp.push_back(t+1);
                ++count;
            } else if (count == k && t <= n) {
                com.push_back(tmp);
                tmp.pop_back();
                st.pop();
                st.push(t+1);
                tmp.push_back(t+1);
            } else if (t > n - k + count) {
                st.pop();
                tmp.pop_back();
                if (st.empty()) {
                    break;
                }
                t = st.top();
                st.pop();
                tmp.pop_back();
                st.push(t+1);
                tmp.push_back(t+1);
                --count;
            }
        }
        return com; 
    }
};

int main() {
    int n = 4;
    int k = 2;
    Solution sol;
    std::vector<std::vector<int>> com = sol.combine(n,k);

    return 0;
}