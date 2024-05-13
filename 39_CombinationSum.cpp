#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> comb;
        int num = candidates.size();
        std::sort(candidates.begin(),candidates.end(),std::greater<int>());
        std::stack<int> st;
        st.push(0);
        std::vector<int> tmp;
        int count = 0;
        while (!st.empty()) {
            int t = st.top();
            int ad = candidates[t];
            count += ad;
            tmp.push_back(ad);
            if (count < target) {
                st.push(t);
            } else {
                if (count == target) {
                    comb.push_back(tmp);
                }
                st.pop();
                count -= ad;
                tmp.pop_back();
                while(t == num - 1 && !st.empty()) {
                    t = st.top();
                    st.pop();
                    count -= candidates[t];
                    tmp.pop_back();
                }
                if (t == num-1) {
                    break;
                } else {
                    st.push(t+1);
                }
            }
        }
        return comb;
    }
};

int main() {
    std::vector<int> candidates = {2,3,6,7};
    int target = 7;
    Solution sol;
    std::vector<std::vector<int>> com = sol.combinationSum(candidates,target);
    return 0;
}