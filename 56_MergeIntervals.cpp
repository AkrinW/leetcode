#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    std::vector<std::vector<int>> merge;
    std::sort(intervals.begin(),intervals.end());
    int n = intervals.size();
    std::vector<int> tmp = intervals[0];
    for (int i = 1; i < n; ++i) {
        if (intervals[i][0] > tmp[1]) {
            merge.push_back(tmp);
            tmp = intervals[i];
        } else {
            tmp[1] = tmp[1] >= intervals[i][1] ? tmp[1] : intervals[i][1];
        }
    }
    merge.push_back(tmp);
    std::cout << merge[0][1];

    return 0;
}