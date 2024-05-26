#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <array>
#include <cctype>
#include <functional>
using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int *que = new int[k+1]{0};
        int count = 0;
        std::function <void(int)> push = [&](int i) {
            if (count < k) {
                int t = count + 1;
                while (t/2 >= 1 && que[t/2] > i) {
                    que[t] = que[t/2];
                    t /= 2;
                }
                que[t] = i;
                ++count;
            } else if (i > que[1]) {
                int t = 1;
                while (i > que[t]) {
                    //find 2t and 2t+1;
                    t *= 2;
                    if (t > k) {
                        break;
                    }  else if (t < k && que[t] > que[t+1]) {
                        ++t;
                    }
                    if (i > que[t]) {
                        que[t/2] = que[t];
                    } else {
                        break;
                    }
                }
                que[t/2] = i;
            }
        };
        // priority_queue<int> que;
        // que.push(matrix[0][0]);
        push(matrix[0][0]);
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 1; i < n; ++i) {
            matrix[0][i] ^= matrix[0][i-1];
            // que.push(matrix[0][i]);
            push(matrix[0][i]);
        }
        for (int i = 1; i < m; ++i) {
            matrix[i][0] ^= matrix[i-1][0];
            // que.push(matrix[i][0]);
            push(matrix[i][0]);
        }
        for (int i = 1; i < m && i < n; ++i) {
            for (int j = i; j < n; ++j) {
                matrix[i][j] ^= (matrix[i-1][j-1] ^ matrix[i-1][j] ^ matrix[i][j-1]);
                // que.push(matrix[i][j]);
                push(matrix[i][j]);
            }
            for (int j = i + 1; j < m; ++j) {
                matrix[j][i] ^= (matrix[j-1][i-1] ^ matrix[j-1][i] ^ matrix[j][i-1]);
                // que.push(matrix[j][i]);
                push(matrix[j][i]);
            }
        }
        // for (int i = 1; i < k; ++i) {
        //     que.pop();
        // }
        return que[1];
    }
};

int main() {
    return 0;
}