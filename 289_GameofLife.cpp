#include <iostream>
#include <vector>

// use more number contain informations to solve gameoflife.
// 0- die2die 1- live2live 2- die2live 3- live2die
// in next traverse, change 2and3 to 0 and 1.
int findCell(int x, int y, std::vector<std::vector<int>>& board) {
    int count = 0;
    int m = board.size();
    int n = board[0].size();
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if ((i !=0 || j != 0) && (x + i > -1 && x + i < m) && (y + j > -1 && y + j < n)) {
                if (board[x+i][y+j] == 1 || board[x+i][y+j] == 3) {
                    ++count;
                }
            }
        }
    }
    return count;
}


int main() {
    int a[4][3] = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    std::vector<std::vector<int>> board;
    for (int i = 0; i < 4; ++i) {
        std::vector<int> tmp(a[i],a[i]+3);
        board.push_back(tmp);
    }
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int count = 0;
            count = findCell(i,j,board);
            if (board[i][j] == 0) {
                if (count == 3) {
                    board[i][j] = 2;
                }
            } else {
                if (count < 2 || count > 3) {
                    board[i][j] = 3;
                }
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 2) {
                board[i][j] = 1;
            } else if (board[i][j] == 3) {
                board[i][j] = 0;
            }
        }
    }
    std::cout << board[0][0];

    return 0;
}