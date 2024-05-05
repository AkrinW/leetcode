#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    std::vector<int> newInterval = {1,17};
    std::vector<std::vector<int>> ins;
    int n = intervals.size();
    if (n == 0) {
        ins.push_back(newInterval);
        return 0;
    }
    int i, j = 0;
    for (i = 0; i < n; ++i) {
        if (newInterval[0] <= intervals[i][1]) {
            break;
        }
    }
    for (j = n - 1; j > -1; --j) {
        if (newInterval[1] >= intervals[j][0]) {
            break;
        }
    }
    for (int k = 0; k < i; ++k) {
        ins.push_back(intervals[k]);
    }
    if (j < i) {
        ins.push_back(newInterval);
    } else {
        std::vector<int> a;
        a.push_back(newInterval[0] < intervals[i][0] ? newInterval[0] : intervals[i][0]);
        a.push_back(newInterval[1] > intervals[j][1] ? newInterval[1] : intervals[j][1]);
        ins.push_back(a); 
    }
    for (int k = j + 1; k < n; ++k) {
        ins.push_back(intervals[k]);
    }
    return 0;
}