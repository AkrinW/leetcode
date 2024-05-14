#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i;
        int up = 0;
        int down = m - 1;
        while (up <= m - 1) {
            int mid = (up + down) / 2;
            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] < target) {
                up = mid + 1;
            } else {
                down = mid - 1;
            }
        }
        i = up - 1;
        if (i == -1) {
            return false;
        } 
        up = 0;
        down = n - 1;
        while (up <= down) {
            int mid = (up + down) / 2;
            if (matrix[i][mid] == target) {
                return true;
            } else if (matrix[i][mid] < target) {
                up = mid + 1;
            } else {
                down = mid - 1;
            }
        }
        return false;
    }
};

int main() {

    return 0;
}