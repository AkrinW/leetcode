#include <iostream>
#include <vector>
//find first 0. use it's vertical and horizon to save 0s

std::vector<std::vector<int>> matrix;

int m, n;
void verzero(int x) {
    for (int i = 0; i < m; ++i) {
        matrix[i][x] = 0;
    }
}
void horzero(int x) {
    for (int i = 0; i < n; ++i) {
        matrix[x][i] = 0;
    }
}

int main() {
    int a[3][4] = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    for (int i = 0; i < 3; ++i) {
        std::vector<int> tmp(a[i],a[i]+4);
        matrix.push_back(tmp);
    }
    m = matrix.size();
    n = matrix[0].size();
    bool flag = false;
    int x, y;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                if (flag) {
                    matrix[x][j] = 0;
                    matrix[i][y] = 0;
                } else {
                    x = i;
                    y = j;
                    flag = true;
                }
            }
        }
    }
    if (flag) {
        for (int i = 0; i < m; ++i) {
            if (matrix[i][y] == 0 && i != x) {
                horzero(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (matrix[x][i] == 0 && i != y) {
                verzero(i);
            }
        }
        horzero(x);
        verzero(y);
    }
    std::cout <<matrix[0][0];

    return 0;
}

