#include <bits/stdc++.h>
using namespace std;

int mat[200][200];
bool used[200][200];
int res[200][200]; // 用于存储每个点到起点的最短距离

int n, m;

int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 0 && used[x][y] == false;
}

void BFS() { // 修改了函数名和参数
    queue<pair<int, int>> q;
    q.push({0, 0});
    used[0][0] = true;
    res[0][0] = 0;

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        int currentX = temp.first;
        int currentY = temp.second;

        for (int d = 0; d < 4; d++) {
            int newX = currentX + dirx[d];
            int newY = currentY + diry[d];
            if (isValid(newX, newY)) {
                q.push({newX, newY});
                used[newX][newY] = true;
                res[newX][newY] = res[currentX][currentY] + 1; // 保存每个点到起点的距离
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    // 初始化结果矩阵为 -1，表示不可达
    memset(res, -1, sizeof(res));
    memset(used, false, sizeof(used));

    // 从起点 (0, 0) 开始 BFS
    if (mat[0][0] == 0) { // 检查起点是否可达
        BFS();
    }

    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j];
            if (j < m - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}