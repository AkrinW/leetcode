#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        double find = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int target = (n1+n2)/2 - 2;
        int n1_p = -1;
        int n2_p = -1;
        int i,j;
        // i, j. i + j + 2 = (n1+n2)/2
        // j = (n1+n2)/2 - 2 - i;
        if (n1 <= n2) {
            int step = n1/2 > 1 ? n1/2 : 1;
            i = -1;
            j = target - i;
            while (true) {
                if (i != n1-1 && j != -1 && nums1[i+1] < nums2[j]) {
                    i += step;
                    step = step/ 2 > 1 ? step/2 : 1;
                    j = target - i;
                } else if (j != n2-1 && i != -1 && nums1[i] > nums2[j+1]) {
                    i -= step;
                    step = step/ 2 > 1 ? step/2 : 1;
                    j = target - i;
                } else {
                    break;
                }
            }
        } else {
            int step = n2/2 > 1? n2/2 : 1;
            j = -1;
            i = target - j;
            while (true) {
                if (j != n2-1 && i != -1 && nums2[j+1] < nums1[i]) {
                    j += step;
                    step = step/ 2 > 1 ? step/2 : 1;
                    i = target - j;
                } else if (i != n1-1 && j != -1 && nums2[j] > nums1[i+1]) {
                    j -= step;
                    step = step/ 2 > 1 ? step/2 : 1;
                    i = target - j;
                } else {
                    break;
                }
            }
        }
        if ((n1+n2)%2 == 1) {
            if (i + 1 == n1) {
                find = nums2[j + 1];
            } else if (j + 1 == n2) {
                find = nums1[i + 1]; 
            } else {
                find = nums2[j + 1] < nums1[i+1] ? nums2[j +1] : nums1[i+1];
            }
        } else {
            double t1,t2;
            if (i == -1) {
                t1 = nums2[j];
            } else if (j == -1) {
                t1 = nums1[i];
            } else {
                t1 = nums1[i] > nums2[j] ? nums1[i] : nums2[j];
            }
            if (i + 1 == n1) {
                t2 = nums2[j + 1];
            } else if (j + 1 == n2) {
                t2 = nums1[i + 1]; 
            } else {
                t2 = nums2[j + 1] < nums1[i+1] ? nums2[j +1] : nums1[i+1];
            }
            find = (t1+t2) / 2 ;
        }
        // if (n1 == 0) {
        //     while (n2_p + 1 != n2/2) {

        //     }
        // }
        // while (n1_p + n2_p + 2 != (n1+n2) / 2) {
        //     if (n1_p != n1 - 1 && (n2_p == n2 -1 || nums1[n1_p] < nums2[n2_p + 1])) {
        //         n1_p += step1;
        //         step1 = step1/2 > 1 ? step1/2 : 1;
        //     } else if (n2_p != n2-1 && (n1_p == n1-1 || nums2[n2_p] < nums1[n1_p+1])) {
        //         n2_p += step2;
        //         step2 = step2/2 > 1 ? step2/2 : 1;
        //     }
        //     if (n2_p == n2 -1 || (n1_p != n1-1 &&nums1[n1_p] > nums2[n2_p + 1])){
        //         n1_p -= step1;
        //         step1 = step2/2 > 1 ? step2/2 : 1;
        //     } else if (n1_p == n1 -1 || (n2_p != n2-1 &&nums2[n2_p] > nums1[n1_p + 1])){
        //         n2_p -= step2;
        //         step2 =  step1/2 > 1 ? step1/2 : 1;
        //     }
        //     // if (n1_p+n2_p+2 < (n1+n2)/2) {
        //     //     if (n1_p == n1 -1 || ((n2_p != n2 -1)&&nums1[n1_p + 1] > nums2[n2_p + 1])){
        //     //         n2_p += step2;
        //     //         step2 = step2/2 > 1 ? step2/2 : 1;
        //     //     } else {
        //     //         n1_p += step1;
        //     //         step1 = step1/2 > 1 ? step1/2 : 1;
        //     //     }
        //     // } else {
        //     //     if (n2_p == n2 -1 || (n1_p != n1-1 &&nums1[n1_p] > nums2[n2_p + 1])){
        //     //         n1_p -= step1;
        //     //         step1 = step2/2 > 1 ? step2/2 : 1;
        //     //     } else if (n1_p == n1 -1 || (n2_p != n2-1 &&nums2[n2_p] > nums1[n1_p + 1])){
        //     //         n2_p -= step2;
        //     //         step2 =  step1/2 > 1 ? step1/2 : 1;
        //     //     }
        //     // }
        // }
        // if (n1_p != n1 - 1 && n2_p != -1 && nums1[n1_p + 1] < nums2[n2_p]) {
        //     ++n1_p;
        //     --n2_p;
        // } else if (n2_p != n2-1 && n1_p != -1 &&  nums2[n2_p+1] < nums1[n1_p]) {
        //     ++n2_p;
        //     --n1_p;
        // }
        // if ((n1+n2)%2 == 1) {
        //     if (n1_p + 1 == n1) {
        //         find = nums2[n2_p + 1];
        //     } else if (n2_p + 1 == n2) {
        //         find = nums1[n1_p + 1]; 
        //     } else {
        //         find = nums2[n2_p + 1] < nums1[n1_p+1] ? nums2[n2_p +1] : nums1[n1_p+1];
        //     }
        // } else {
        //     double t1,t2;
        //     if (n1_p == -1) {
        //         t1 = nums2[n2_p];
        //     } else if (n2_p == -1) {
        //         t1 = nums1[n1_p];
        //     } else {
        //         t1 = nums1[n1_p] > nums2[n2_p] ? nums1[n1_p] : nums2[n2_p];
        //     }
        //     if (n1_p + 1 == n1) {
        //         t2 = nums2[n2_p + 1];
        //     } else if (n2_p + 1 == n2) {
        //         t2 = nums1[n1_p + 1]; 
        //     } else {
        //         t2 = nums2[n2_p + 1] < nums1[n1_p+1] ? nums2[n2_p +1] : nums1[n1_p+1];
        //     }
        //     find = (t1+t2) / 2 ;
        // }
        return find;
    }
};

int main() {
    std::vector<int> n1 = {1,2,3,5};
    std::vector<int> n2 = {4,6,7,8};

    Solution sol;
    sol.findMedianSortedArrays(n1,n2);
    return 0;
}