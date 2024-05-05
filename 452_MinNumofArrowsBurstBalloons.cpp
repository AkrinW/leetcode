#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::vector<int>> points = {{1,2},{2,3},{3,4},{4,5}};
    std::sort(points.begin(),points.end());
    int i = points[0][0], j = points[0][1];
    int n = points.size();
    int min = 1;
    for (int k = 1; k < n; ++k) {
        if (points[k][0] <= j) {
            i = i >= points[k][0] ? i : points[k][0];
            j = j <= points[k][1] ? j : points[k][1];
        } else {
            ++min;
            i = points[k][0];
            j = points[k][1];
        }
    }
    std::cout << min;
    return 0;
}