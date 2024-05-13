#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> per;
        std::stack<int> st;
        int count = 0;
        bool *flags = new bool[n];
        for (int i = 0; i < n; ++i) {
            flags[i] = true;
        }
        std::vector<int> tmp;
        tmp.push_back(nums[0]);
        st.push(0);
        flags[0] = false;
        ++count;
        while (!st.empty()) {
            if (count < n) {
                int i = 0;
                while (!flags[i] && i < n) {
                    ++i;
                }
                st.push(i);
                flags[i] = false;
                ++count;
                tmp.push_back(nums[i]);
            } else {
                per.push_back(tmp);
                tmp.pop_back();
                --count;
                int t = st.top();
                flags[t] = true;
                st.pop();
                while (!st.empty() && st.top()>t) {
                    t = st.top();
                    flags[t] = true;
                    --count;
                    tmp.pop_back();
                    st.pop();
                }
                if (st.empty()) {
                    break;
                }
                t = st.top();
                flags[t] = true;
                --count;
                st.pop();
                tmp.pop_back();
                do {
                    ++t;
                } while (flags[t] == false);
                flags[t] = false;
                st.push(t);
                tmp.push_back(nums[t]);
                ++count;
            }
        }  
        return per; 
    }
};

int main() {
    std::vector<int> nums = {1,2,3};
    Solution sol;
    std::vector<std::vector<int>> per = sol.permute(nums);
    return 0;
}