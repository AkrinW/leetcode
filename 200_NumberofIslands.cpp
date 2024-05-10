#include <vector>
#include <string>
#include <stack>
std::pair<int,int> neib;
// queue<pair<int, int>> neighbors;
class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> checked;
        std::stack<int> st1,st2;
        for (int i = 0; i < m; ++i) {
            std::vector<int> tmp;
            for (int j = 0; j < n; ++j) {
                tmp.push_back(0);
            }
            checked.push_back(tmp);
        }
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (checked[i][j] == 0) {
                    if (grid[i][j] == '1') {
                        ++count;
                        st1.push(i);
                        st2.push(j);
                        checked[i][j] = 1;
                        while (!st1.empty()) {
                            int a = st1.top();
                            int b = st2.top();
                            st1.pop();
                            st2.pop();
                            if (a > 0 && checked[a-1][b] == 0) {
                                if (grid[a-1][b] == '1') {
                                    st1.push(a-1);
                                    st2.push(b);
                                }
                                checked[a-1][b] = 1;
                            }
                            if (a < m-1 && checked[a+1][b] == 0) {
                                if (grid[a+1][b] == '1') {
                                    st1.push(a+1);
                                    st2.push(b);
                                }
                                checked[a+1][b] = 1;
                            }
                            if (b > 0 && checked[a][b-1] == 0) {
                                if (grid[a][b-1] == '1') {
                                    st1.push(a);
                                    st2.push(b-1);
                                }
                                checked[a][b-1] = 1;
                            }
                            if (b < n-1 && checked[a][b+1] == 0) {
                                if (grid[a][b+1] == '1') {
                                    st1.push(a);
                                    st2.push(b+1);
                                }
                                checked[a][b+1] = 1;
                            }
                        }
                    }
                } 
            }
        }
        return count;
    }
};
int main() {
    std::stack<int[2]> st;
    return 0;
}