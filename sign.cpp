
#include <iostream>
using namespace std;

// [0][0] 统计点个数 [0][i] 统计出现的点
// [i][0] 统计点顺序 [1][1] 统计边个数 [2][2] 统计已连接的边
int graph[10][10] = {0};
void check(int i,int last,int r);
void dfs(int r) {
    if (r == graph[0][0] && graph[1][1] == graph[2][2]) {
        for (int i = 1; i <= r; ++i) {
            cout << graph[i][0] << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = 1; i < 10; ++i) {
        if (graph[0][i] == 0) {
            continue;
        }
        // 当前点未连接，考虑它能否和上个点相连
        if (r == 0) {
            graph[r+1][0] = i;
            graph[0][i] = 0;
            dfs(r+1);
            graph[0][i] = 1;
        } else {
            int last = graph[r][0];
            if (graph[last][i] == 1) {
                // 可连接，直接连接
                graph[r+1][0] = i;
                graph[0][i] = 0;
                graph[2][2]++;
                graph[last][i] = -1;
                graph[i][last] = -1;
                dfs(r+1);
                graph[0][i] = 1;
                graph[2][2]--;
                graph[last][i] = 1;
                graph[i][last] = 1;
            } else if (graph[last][i] == -1){
                // 没有直接连接，需要考虑能否跨点相连。
                // 13 17 19 31 37 39 71 73 79 91 93 97
                // 28 46 64 82
                continue;
            } else {
                switch (i) {
                case 1:
                    if (last == 3 || last == 7 || last == 9) {
                        check(i,last,r);
                    }
                    break;
                case 3:
                    if (last == 1 || last == 7 || last == 9) {
                        check(i,last,r);
                    }
                    break;
                case 7:
                    if (last == 1 || last == 3 || last == 9) {
                        check(i,last,r);
                    }
                    break;
                case 9:
                    if (last == 1 || last == 3 || last == 7) {
                        check(i,last,r);
                    }
                    break;
                case 2:
                    if (last == 8) {
                        check(i,last,r);
                    }
                    break;
                case 4:
                    if (last == 6) {
                        check(i,last,r);
                    }
                    break;
                case 6:
                    if (last == 4) {
                        check(i,last,r);
                    }
                    break;
                case 8:
                    if (last == 2) {
                        check(i,last,r);
                    }
                    break;
                default:
                    break;
                }
            }
        }
    }
}

void check(int i,int last,int r) {
    int avr = (i+last)/2;
    if (graph[avr][i] == -1 && graph[avr][last] == 1){
        graph[r+1][0] = i;
        graph[0][i] = 0;
        graph[2][2]++;
        graph[avr][last] = -1;
        graph[last][avr] = -1;
        dfs(r+1);
        graph[0][i] = 1;
        graph[2][2]--;
        graph[last][avr] = 1;
        graph[avr][last] = 1;
    } else if (graph[avr][i] == 1 && graph[avr][last] == -1) {
        graph[r+1][0] = i;
        graph[0][i] = 0;
        graph[2][2]++;
        graph[avr][i] = -1;
        graph[i][avr] = -1;
        dfs(r+1);
        graph[0][i] = 1;
        graph[2][2]--;
        graph[i][avr] = 1;
        graph[avr][i] = 1;
    } else if (graph[avr][i]== 1 && graph[avr][last] == 1 && graph[0][avr] == 0) {
        graph[r+1][0] = i;
        graph[0][i] = 0;
        graph[2][2]++;
        graph[2][2]++;
        graph[avr][i] = -1;
        graph[i][avr] = -1;
        graph[avr][last] = -1;
        graph[last][avr] = -1;
        dfs(r+1);
        graph[0][i] = 1;
        graph[2][2]--;
        graph[2][2]--;
        graph[i][avr] = 1;
        graph[avr][i] = 1;
        graph[avr][last] = 1;
        graph[last][avr] = 1;
    }
} 

int main() {
    int n;
    cin >> n;
    for (int i = 0;i < n; ++i) {
        int u,v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
        graph[0][u] = 1;// 统计出现哪些点。
        graph[0][v] = 1;
    }
    for (int i = 1; i < 10; ++i) {
        graph[0][0] += graph[0][i];
    }
    graph[1][1] = n;
    // 暴力搜索。O(2^n)
    dfs(0);
    return 0;
}