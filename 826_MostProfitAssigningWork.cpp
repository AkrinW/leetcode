#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>
using namespace std;
// 6.18 rewrite
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(), worker.end());
        std::vector<pair<int, int>> pair;
        int n = difficulty.size();
        for (int i = 0; i < n; ++i) {
            pair.push_back({difficulty[i], profit[i]});
        }
        sort(pair.begin(), pair.end());
        int max = 0;
        int submax = 0;
        int i = 0;
        for (auto u: worker) {
            while (i < n) {
                if (pair[i].first > u) {
                    break;
                } else {
                    submax = submax > pair[i].second ? submax : pair[i].second;
                    ++i;
                }
            }
            max += submax;
        }
        return max;
    }
};


// 5.17 write
class Solution {
private:
void merge(std::vector<int>& arr, int left, int mid, int right, std::vector<int>& profit) {
    // Calculate sizes of two subarrays to be merged
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    std::vector<int> L(n1);
    std::vector<int> R(n2);
    std::vector<int> L2(n1);
    std::vector<int> R2(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; ++i){
        L[i] = arr[left + i];
        L2[i] = profit[left+i];
    }
    for (int i = 0; i < n2; ++i){
        R[i] = arr[mid + 1 + i];
        R2[i] = profit[mid + 1+i];
    }
    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            profit[k] = L2[i];
            ++i;
        } else {
            arr[k] = R[j];
            profit[k] = R2[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        profit[k] = L2[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        profit[k] = R2[j];
        ++j;
        ++k;
    }
}

// Iterative MergeSort function
void mergeSort(std::vector<int>& arr, std::vector<int>& profit) {
    int n = arr.size();
    // For current size of subarrays to be merged curr_size varies from 1 to n/2
    for (int curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        // Pick starting point of different subarrays of current size
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            // Find ending point of left subarray. mid+1 is starting point of right
            int mid = std::min(left_start + curr_size - 1, n - 1);
            int right_end = std::min(left_start + 2 * curr_size - 1, n - 1);

            // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
            merge(arr, left_start, mid, right_end, profit);
        }
    }
}

public:
    int maxProfitAssignment(std::vector<int>& difficulty, std::vector<int>& profit, std::vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        mergeSort(difficulty,profit);
        for (int i = 1; i < n; ++i) {
            int tmp = i;
            int max = profit[i-1];
            while (difficulty[tmp] == difficulty[tmp-1]) {
                max = max > profit[tmp] ? max : profit[tmp];
                ++tmp;
            }
            profit[i-1] = max;
            while (difficulty[i] == difficulty[i-1]) {
                profit[i] = max;
                ++i;
            }
            if (profit[i] < profit[i-1]) {
                profit[i] = profit[i-1];
            }
        }
        int max = 0;
        for (int i = 0; i < m; ++i) {
            int start = 0;
            int end = n - 1;
            while (start <= end) {
                int mid = (start+end) / 2;
                if (difficulty[mid] == worker[i]) {
                    end = mid;
                    start = mid+1;
                } else if (difficulty[mid] > worker[i]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            if (end != -1) {
                max += profit[end];
            }
        }
        return max;
    }
};


int main() {

    return 0;
}