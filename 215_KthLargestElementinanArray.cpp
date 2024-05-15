#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        int n = nums.size();
        int find;
        int *heap = new int[k+1];
        for (int i = 1; i < k+1; ++i) {
            int t = i;
            while (nums[i-1] < heap[t/2]) {
                heap[t] = heap[t/2];
                t /= 2;
            }
            heap[t] = nums[i-1];
        }
        for (int i = k; i < n; ++i) {
            if (nums[i] >= heap[1]) {
                int t = 2;
                while (t < k + 1) {
                    if (t != k && heap[t] > heap[t+1]) {
                        t = t+1;
                    }
                    if (nums[i] >= heap[t]) {
                        heap[t/2] = heap[t];
                        t *= 2;
                    } else {
                        break;
                    }
                }
                heap[t/2] = nums[i];
            }
        }
        return heap[0];
    }
};


int main() {
    std::vector<int> n2 = {4,6,7,8};

    Solution sol;
    sol.findKthLargest(n2, 2);
    return 0;
}