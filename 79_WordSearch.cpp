#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

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
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int m = board.size();
        int n = board[0].size();
        std::vector<std::pair<int,int>> map[60];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char tmp = board[i][j];
                map[tmp-'A'].push_back({i,j});
            }
        }
        std::string toCompare = word;
        int len = toCompare.size();
        for (int j = 0; j < len; ++j) {
            if (map[toCompare[j]-'A'].size() == 0) {
                return false;
            }
        }
        char tmp = toCompare[0];
        char tmp2 = toCompare[len-1];
        if (map[tmp-'A'].size() > map[tmp2-'A'].size()) {
            tmp = tmp2;
            std::reverse(toCompare.begin(),toCompare.end());
        }
        int startpos = map[tmp-'A'].size();
        for (int j = 0; j < startpos; ++j) {
            std::stack<Node> st;
            Node p(map[tmp-'A'][j].first,map[tmp-'A'][j].second,0);
            st.push(p);
            board[p.x][p.y] -= 60;
            int count = 1;
                // 0:x-1 y 1:x+1 y 2:x y-1 3:x y+1
            while (!st.empty()) {
                if (count == len) {
                    while(!st.empty()) {
                        int x = st.top().x;
                        int y = st.top().y;
                        board[x][y] += 60;
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
                        board[x-1][y] -= 60;
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
                        board[x+1][y] -= 60;
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
                        board[x][y-1] -= 60;
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
                        board[x][y+1] -= 60;
                        ++count;
                    } else {
                        ++dec;
                    }
                }
                if (dec == 4) {
                    board[x][y] += 60;
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
                return true;
            }
        }
        return false;
    }
};

int main() {
    std::vector<std::vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    std::string word =  "ABCCED";
    Solution sol;
    bool ex = sol.exist(board, word);
    return 0;
}