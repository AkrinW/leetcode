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
private:
    static bool flag;
    static vector<long long> A1;
    static vector<long long> L1_A0;
    static vector<long long> L2_A0;
    static vector<long long> P_A0;
    static vector<long long> L1_A1;
    static vector<long long> L2_A1;
    static vector<long long> P_A1;
    void init() {
        A1.push_back(0);
        L1_A0.push_back(0);
        L2_A0.push_back(0);
        P_A0.push_back(0);
        L1_A1.push_back(0);
        L2_A1.push_back(0);
        P_A1.push_back(0);

        A1.push_back(1);
        L1_A0.push_back(1);
        L2_A0.push_back(0);
        P_A0.push_back(1);
        L1_A1.push_back(0);
        L2_A1.push_back(0);
        P_A1.push_back(0);
        
        for (int i = 2; i < 100001; ++i) {
            A1.push_back((L1_A0[i-1]+L2_A0[i-1]+P_A0[i-1]) % long(1e9+7));
            L1_A0.push_back(P_A0[i-1]);
            L2_A0.push_back(L1_A0[i-1]);
            P_A0.push_back((L1_A0[i-1]+L2_A0[i-1]+P_A0[i-1]) % long(1e9+7));
            L1_A1.push_back((A1[i-1] + P_A1[i-1]) % long(1e9+7));
            L2_A1.push_back(L1_A1[i-1]);
            P_A1.push_back((A1[i-1]+L1_A1[i-1]+L2_A1[i-1]+P_A1[i-1]) % long(1e9+7));
        }
    }
public:
    Solution() {
        if (!flag) {
            init();
            flag = true;
        }
    }

    int checkRecord(int n) {
        long p = A1[n] + L1_A0[n] + L2_A0[n] + P_A0[n] + L1_A1[n] + L2_A1[n] + P_A1[n];
        p = p % long(1e9+7);
        return int(p);
    }
};
bool Solution::flag = false;
vector<long long> Solution::A1;
vector<long long> Solution::L1_A0;
vector<long long> Solution::L2_A0;
vector<long long> Solution::P_A0;
vector<long long> Solution::L1_A1;
vector<long long> Solution::L2_A1;
vector<long long> Solution::P_A1;

int main() {
    Solution sol;
    sol.checkRecord(10);
    return 0;
}