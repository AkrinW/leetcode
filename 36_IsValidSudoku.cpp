#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
int main() {
    std::vector<std::vector<char>> board;
    std::string a[9][9] = {{"8","3",".",".","7",".",".",".","."}
                ,{"6",".",".","1","9","5",".",".","."}
                ,{".","9","8",".",".",".",".","6","."}
                ,{"8",".",".",".","6",".",".",".","3"}
                ,{"4",".",".","8",".","3",".",".","1"}
                ,{"7",".",".",".","2",".",".",".","6"}
                ,{".","6",".",".",".",".","2","8","."}
                ,{".",".",".","4","1","9",".",".","5"}
                ,{".",".",".",".","8",".",".","7","9"}};
    for (int i = 0; i < 9; ++i) {
        std::vector<char> tmp;
        for (int j = 0; j < 9; ++j) {
            tmp.push_back(a[i][j][0]);
        }
        board.push_back(tmp);
    }
    bool flag = true;
    std::unordered_map<char, int> hash;
    for (int i = 0; i < 9; ++i) {
        hash.clear();
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] <= '9' && board[i][j] >= '0') {
                ++hash[board[i][j]];
                if (hash[board[i][j]] > 1) {
                    flag = false;
                    return 0;
                }
            }
        }
        hash.clear();
        for (int j = 0; j < 9; ++j) {
            if (board[j][i] <= '9' && board[j][i] >= '0') {
                ++hash[board[j][i]];
                if (hash[board[j][i]] > 1) {
                    flag = false;
                    return 0;
                }
            }
        }
    }
    for (int i = 0; i < 9; ++i) {
        hash.clear();
        if (board[i][i] <= '9' && board[i][i] >= '0') {
            ++hash[board[i][i]];
            if (hash[board[i][i]] > 1) {
                flag = false;
                return 0;
            }
        }
    }
    for (int i = 0; i < 9; ++i) {
        hash.clear();
        if (board[8-i][i] <= '9' && board[8-i][i] >= '0') {
            ++hash[board[8-i][i]];
            if (hash[board[8-i][i]] > 1) {
                flag = false;
                return 0;
            }
        }
    }
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            hash.clear();
            for (int m = 0; m < 3; ++m) {
                for (int n = 0; n < 3; ++n) {
                    char tmp = board[i+m][j+n];
                    if (tmp <= '9' && tmp >= '0') {
                        ++hash[tmp];
                        if (hash[tmp] > 1) {
                            flag = false;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}