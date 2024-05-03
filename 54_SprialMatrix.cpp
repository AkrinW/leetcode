#include <iostream>
#include <vector>

int main() {
    int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < 3; ++i) {
        std::vector<int> tmp(a[i],a[i]+4);
        matrix.push_back(tmp);
    }
    std::vector<int> sprialorder;
    int width = matrix[0].size();
    int height = matrix.size();
    int m = width;
    int n = height - 1;
    int i = -1;
    int j = 0;
    bool toright = true;
    bool todown = true;
    while (true) {
        if (m == 0) {
            break;
        }
        if (toright) {
            for (int x = 1; x <= m; ++x) {
                sprialorder.push_back(matrix[j][i+x]);
            }
            i += m;
            toright = false;
        } else {
            for (int x = 1; x <= m; ++x) {
                sprialorder.push_back(matrix[j][i-x]);
            }
            i -= m;
            toright = true;
        }
        --m;
        if (n == 0) {
            break;
        }
        if (todown) {
            for (int x = 1; x <= n; ++x) {
                sprialorder.push_back(matrix[j+x][i]);
            }
            j += n;
            todown = false;
        } else {
            for (int x = 1; x <= n; ++x) {
                sprialorder.push_back(matrix[j-x][i]);
            }
            j -= n;
            todown = true;
        }
        --n;
    }
    std::cout << sprialorder[0];
    return 0;
}