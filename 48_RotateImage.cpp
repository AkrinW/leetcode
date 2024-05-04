#include <iostream>
#include <vector>

int main() {
    int a[4][4] = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < 4; ++i) {
        std::vector<int> tmp(a[i],a[i]+4);
        matrix.push_back(tmp);
    }
    int n = matrix.size();
    int x, y;
    int tmp;
    int i, j; // i[0, n/2] j[0, n+1/2]
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < (n+1)/2; ++j) {
            x = i;
            y = j;
            tmp = matrix[x][y];
            for (int count = 0; count < 3; ++count) {
                matrix[x][y] = matrix[n-1-y][x];
                int t = x;
                x = n - 1 - y;
                y = t;
            }
            matrix[x][y] = tmp;
        }
    }
    std::cout << matrix[0][0];



    return 0;
}