#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
private:
    struct Graph {
        std::vector<int> next;
    };
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        bool flag = false;
        std::unordered_map<int,int> map;
        std::queue<int> que;
        int num = prerequisites.size();
        int count = 0;
        Graph *g = new Graph[numCourses];
        for (int i = 0; i < num; ++i) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            g[b].next.push_back(a);
            ++map[a];
        }
        for (int i = 0; i < numCourses; ++i) {
            if (map[i] == 0) {
                que.push(i);
            }
        }
        while (!que.empty()) {
            int a = que.front();
            int next = g[a].next.size();
            for (int i = 0; i < next; ++i) {
                int tmp = g[a].next[i];
                --map[tmp];
                if (map[tmp] == 0) {
                    que.push(tmp);
                }
            }
            que.pop();
            ++count;
        }
        if (count == numCourses) {
            flag = true;
        }
        return flag;
    }
};

int main() {
    Solution sol;
    int num = 2;
    std::vector<std::vector<int>> pre = {{0,1}};
    std::cout << sol.canFinish(num,pre);

    return 0;
}