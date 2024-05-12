#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
//'a'-'A' = 32
class Solution {
private:
    struct Node {
        int x;
        int y;
        int d;
        Node(int _x, int _y, int _d) {
            x = _x;
            y = _y;
            d = _d;
        }
    };
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        int m = board.size();
        int n = board[0].size();
        std::vector<std::pair<int,int>> word[26];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char tmp = board[i][j];
                word[tmp-'a'].push_back({i,j});
            }
        }
        std::vector<std::string> find;
        int num = words.size();
        for (int i = 0; i < num; ++i) {
            std::string toCompare = words[i];
            int len = toCompare.size();
            for (int j = 0; j < len; ++j) {
                if (word[toCompare[j]-'a'].size() == 0) {
                    len = -1;
                }
            }
            if (len == -1) {
                continue;
            }
            char tmp = toCompare[0];
            char tmp2 = toCompare[len-1];
            if (word[tmp-'a'].size() > word[tmp2-'a'].size()) {
                tmp = tmp2;
                std::reverse(toCompare.begin(),toCompare.end());
            }
            int startpos = word[tmp-'a'].size();
            for (int j = 0; j < startpos; ++j) {
                std::stack<Node> st;
                Node p(word[tmp-'a'][j].first,word[tmp-'a'][j].second,0);
                st.push(p);
                board[p.x][p.y] -= 32;
                int count = 1;
                // 0:x-1 y 1:x+1 y 2:x y-1 3:x y+1
                while (!st.empty()) {
                    if (count == len) {
                        while(!st.empty()) {
                            int x = st.top().x;
                            int y = st.top().y;
                            board[x][y] += 32;
                            st.pop();
                        }
                        break;
                    }
                    int x = st.top().x;
                    int y = st.top().y;
                    int dec = st.top().d;
                    if (dec == 0) {
                        if (x > 0 && board[x-1][y] == toCompare[count]) {
                            st.push(Node(x-1,y,0));
                            board[x-1][y] -= 32;
                            ++count;
                        } else {
                            ++dec;
                        }
                    }
                    if (dec == 1) {
                        if (x < m-1 && board[x+1][y] == toCompare[count]) {
                            st.pop();
                            st.push(Node(x,y,1));
                            st.push(Node(x+1,y,0));
                            board[x+1][y] -= 32;
                            ++count;
                        } else {
                            ++dec;
                        }
                    }
                    if (dec == 2) {
                        if (y > 0 && board[x][y-1] == toCompare[count]) {
                            st.pop();
                            st.push(Node(x,y,2));
                            st.push(Node(x,y-1,0));
                            board[x][y-1] -= 32;
                            ++count;
                        } else {
                            ++dec;
                        }
                    }
                    if (dec == 3) {
                        if (y < n-1 && board[x][y+1] == toCompare[count]) {
                            st.pop();
                            st.push(Node(x,y,3));
                            st.push(Node(x,y+1,0));
                            board[x][y+1] -= 32;
                            ++count;
                        } else {
                            ++dec;
                        }
                    }
                    if (dec == 4) {
                        board[x][y] += 32;
                        --count;
                        st.pop();
                        if (st.empty()) {
                            break;
                        }
                        Node out = st.top();
                        st.pop();
                        ++out.d;
                        st.push(out);
                    }
                }
                if (count == len) {
                    find.push_back(words[i]);
                    break;
                }
            }
            
        }
        return find;
    }
};

int main() {
    std::vector<std::vector<char>> board = {{'a','b'},{'c','d'}};
    std::vector<std::string> words = {"oath","pea","eat","rain"};
    Solution sol;
    std::vector<std::string> find = sol.findWords(board,words);
    std::cout << int('a' -'A');
    std::string a = words[0];
    std::reverse(a.begin(),a.end());
    std::cout <<a;
    return 0;
}