#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
public:
    int totalNQueens(int n) {
        //N*N chessboard, numbered (1,1)-(n,n);
        //Traverse backtracing y and maintain three tables: x, x-y, x+y
        std::stack<int> st;
        bool *flagx = new bool[n];
        bool *flagxmy = new bool[2*n-1];
        bool *flagxpy = new bool[2*n-1];
        int solve = 0;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            flagx[i] = true;
        }
        for (int i = 0; i < 2*n-1; ++i) {
            flagxmy[i] = true;
            flagxpy[i] = true;
        }
        st.push(1);
        flagx[0] = false;
        flagxmy[n-1] = false;
        flagxpy[0] = false;
        ++count;
        while (!st.empty()) {
            int i = 1;
            if (count < n) {
                ++count;
            } else {
                ++solve;
                i = st.top();
                flagx[i-1] = true;
                flagxmy[i-count+n-1] = true;
                flagxpy[i+count-2] = true;
                ++i;
                st.pop();
            }
            for (; i <= n; ++i) {
                if (flagx[i-1] && flagxmy[i-count+n-1] && flagxpy[i-2+count]) {
                    st.push(i);
                    flagx[i-1] = false;
                    flagxmy[i-count+n-1] = false;
                    flagxpy[i+count-2] = false;
                    break;
                }
            }
            while (i == n+1 && !st.empty()) {
                --count;
                i = st.top();
                flagx[i-1] = true;
                flagxmy[i-count+n-1] = true;
                flagxpy[i+count-2] = true;
                ++i;
                st.pop();
                for (;i <= n; ++i) {
                    if (flagx[i-1] && flagxmy[i-count+n-1] && flagxpy[i+count-2]) {
                        st.push(i);
                        flagx[i-1] = false;
                        flagxmy[i-count+n-1] = false;
                        flagxpy[i+count-2] = false;
                        break;
                    }
                }
            }
            if (st.empty()) {
                break;
            }
        }
        return solve;
    }
};

int main() {
    int n = 4;
    Solution sol;
    int t = sol.totalNQueens(n);
    return 0;
}