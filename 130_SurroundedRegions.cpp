#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    void solve(std::vector<std::vector<char>>& board) {
        std::stack<std::pair<int,int>> st;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < n; ++i) {
            if (board[0][i] == 'O') {
                board[0][i] = '-';
                st.push({0,i});
                while (!st.empty()) {
                    int a = st.top().first;
                    int b = st.top().second;
                    st.pop();
                    if (a > 0 && board[a-1][b] == 'O') {
                        board[a-1][b] = '-';
                        st.push({a-1,b});
                    }
                    if (a < m-1 && board[a+1][b] == 'O') {
                        board[a+1][b] = '-';
                        st.push({a+1,b});
                    }
                    if (b > 0 && board[a][b-1] == 'O') {
                        board[a][b-1] = '-';
                        st.push({a,b-1});
                    }
                    if (b < n - 1 && board[a][b+1] == 'O') {
                        board[a][b+1] = '-';
                        st.push({a,b+1});
                    }
                }
            }
            if (board[m-1][i] == 'O') {
                board[m-1][i] = '-';
                st.push({m-1,i});
                while (!st.empty()) {
                    int a = st.top().first;
                    int b = st.top().second;
                    st.pop();
                    if (a > 0 && board[a-1][b] == 'O') {
                        board[a-1][b] = '-';
                        st.push({a-1,b});
                    }
                    if (a < m-1 && board[a+1][b] == 'O') {
                        board[a+1][b] = '-';
                        st.push({a+1,b});
                    }
                    if (b > 0 && board[a][b-1] == 'O') {
                        board[a][b-1] = '-';
                        st.push({a,b-1});
                    }
                    if (b < n - 1 && board[a][b+1] == 'O') {
                        board[a][b+1] = '-';
                        st.push({a,b+1});
                    }
                }
            }
        }
        for (int i = 1; i < m-1; ++i) {
            if (board[i][0] == 'O') {
                board[i][0] = '-';
                st.push({i,0});
                while (!st.empty()) {
                    int a = st.top().first;
                    int b = st.top().second;
                    st.pop();
                    if (a > 0 && board[a-1][b] == 'O') {
                        board[a-1][b] = '-';
                        st.push({a-1,b});
                    }
                    if (a < m-1 && board[a+1][b] == 'O') {
                        board[a+1][b] = '-';
                        st.push({a+1,b});
                    }
                    if (b > 0 && board[a][b-1] == 'O') {
                        board[a][b-1] = '-';
                        st.push({a,b-1});
                    }
                    if (b < n - 1 && board[a][b+1] == 'O') {
                        board[a][b+1] = '-';
                        st.push({a,b+1});
                    }
                }
            }
            if (board[i][n-1] == 'O') {
                board[i][n-1] = '-';
                st.push({i,n-1});
                while (!st.empty()) {
                    int a = st.top().first;
                    int b = st.top().second;
                    st.pop();
                    if (a > 0 && board[a-1][b] == 'O') {
                        board[a-1][b] = '-';
                        st.push({a-1,b});
                    }
                    if (a < m-1 && board[a+1][b] == 'O') {
                        board[a+1][b] = '-';
                        st.push({a+1,b});
                    }
                    if (b > 0 && board[a][b-1] == 'O') {
                        board[a][b-1] = '-';
                        st.push({a,b-1});
                    }
                    if (b < n - 1 && board[a][b+1] == 'O') {
                        board[a][b+1] = '-';
                        st.push({a,b+1});
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == '-') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};


int main() {


    return 0;
}