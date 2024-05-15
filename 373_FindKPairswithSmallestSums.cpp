#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::vector<std::vector<int>> small;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int sub1 = 0;
        int sub2 = 0;
        int *sub1Heap = new int[k+1];
        int *sub2Heap = new int[k+1];
        // std::pair<int, int> *sub = new std::pair<int,int>[k+1];
        int count = 1;
        for (int i = 0; i < k; ++i) {
            for (sub1 = 0; sub1 <= i; ++sub1) {
                sub2 = i - sub1;
                if (sub1 >= n1 || sub2 >= n2) {
                    continue;
                }
                //容量k的最大化堆,存最小的k个值.
                int tmp = nums1[sub1] + nums2[sub2];
                if (count < k + 1) {
                    int t = count;
                    while (t >= 2 && tmp > sub1Heap[t/2] + sub2Heap[t/2]) {
                        sub1Heap[t] = sub1Heap[t/2];
                        sub2Heap[t] = sub2Heap[t/2];
                        t /= 2;
                    }
                    sub1Heap[t] = nums1[sub1];
                    sub2Heap[t] = nums2[sub2];
                    // sub[t] = {nums1[sub1],nums2[sub2]};
                    ++count;
                } else {
                    int t = 1;
                    // if (tmp < sub[t].first + sub[t].second) {
                    if (tmp < sub1Heap[t]+sub2Heap[t]) {
                        bool flag = true;
                        while (flag) {
                            t *= 2;
                            if (t > k) {
                                flag = false;
                            } else if (t == k) {
                                // int tmpleft = sub[t].first + sub[t].second;
                                int tmpleft = sub1Heap[t] + sub2Heap[t];
                                if (tmp < tmpleft) {
                                    // sub[t/2] = sub[t];
                                    sub1Heap[t/2] = sub1Heap[t];
                                    sub2Heap[t/2] = sub2Heap[t];
                                } else {
                                    flag = false;
                                }
                            } else if (t < k) {
                                // int tmpleft = sub[t].first + sub[t].second;
                                // int tmpright = sub[t+1].first +sub[t+1].second;
                                int tmpleft = sub1Heap[t] + sub2Heap[t];
                                int tmpright = sub1Heap[t+1] + sub2Heap[t+1];
                                if (tmpleft < tmpright) {
                                    ++t;
                                    tmpleft = tmpright;
                                }
                                if (tmp < tmpleft) {
                                    // sub[t/2] = sub[t];
                                    sub1Heap[t/2] = sub1Heap[t];
                                    sub2Heap[t/2] = sub2Heap[t];
                                } else {
                                    flag = false;
                                }
                            }
                        }
                        sub1Heap[t/2] = nums1[sub1];
                        sub2Heap[t/2] = nums2[sub2];
                        // sub[t/2] = {nums1[sub1],nums2[sub2]};
                    }
                }
            }
        }
        for (int i = 0; i < k; ++i) {
            std::vector<int> tmp = {sub1Heap[i+1],sub2Heap[i+1]};
            // tmp.push_back(sub[i+1].first);
            // tmp.push_back(sub[i+1].second);
            small.push_back(tmp);
        }
        return small;
    }
};

int main() {
    std::vector<int> nums1 = {0,    0,  0,  0,  0,  2,  2,  2,  2};
    std::vector<int> nums2 = {-3,   22, 35, 56, 76};
    Solution sol;
    sol.kSmallestPairs(nums1,nums2,22);
    return 0;
}