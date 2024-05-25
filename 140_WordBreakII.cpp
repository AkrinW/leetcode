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
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        //使用set，方便查找单词
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        string str = "";
        dfs(s, st, 0, str);
        return ans;
    }
    vector<string> ans;//答案

    /* 回溯法 */
    //     待拆分字符串           单词字典       拆分起始位置     当前正在拼接的句子
    void dfs(string& s, unordered_set<string>& st, int idx, string& cur){
        int n = s.size();
        if(idx == n){
            //找到了一个句子
            ans.push_back(cur);
            return;
        }

        for(int j=idx; j<n; ++j){
            string word = s.substr(idx, j-idx+1);
            if(st.find(word) != st.end()){//找到一个新单词
                int pos = cur.size();
                if(pos > 0){
                    cur.append(" ");
                }
                cur.append(word);//这个单词加入当前的句子中
                dfs(s, st, j+1, cur);//递归调用，从j+1处继续往后拆分字符串s
                cur.erase(cur.begin() + pos, cur.end());//从当前的句子中移除这个单词
            }
        }
    }
};;

int main() {
    return 0;
}