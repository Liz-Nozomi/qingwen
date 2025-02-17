
#include <bits/stdc++.h>
using namespace std;
int mat[200][200];
bool visited[200];  // 记录节点是否被访问过
bool onPath[200];   // 记录当前路径上的节点
int n, m;

bool DFS(int idx) {
    if (onPath[idx]) return true;  // 如果当前节点已经在路径上，说明存在环
    if (visited[idx]) return false;  // 如果当前节点已经被访问过，但不在路径上，说明没有环

    visited[idx] = true;  // 标记当前节点为已访问
    onPath[idx] = true;   // 将当前节点加入路径

    for (int i = 0; i < n; i++) {
        if (mat[idx][i] == 1) {  // 如果存在边
            if (DFS(i)) return true;  // 递归检测
        }
    }

    onPath[idx] = false;  // 回溯，将当前节点从路径中移除
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        mat[x][y] = 1;  // 有向图
        // mat[y][x] = 1; // 如果是无向图，需要添加这行
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && DFS(i)) {
            cout << "Yes" << endl;  // 存在环
            return 0;
        }
    }

    cout << "No" << endl;  // 不存在环
    return 0;
}