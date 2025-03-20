#include <bits/stdc++.h>
using namespace std;

bool rockmap[110][110];
bool visited[110][110];
vector<string> res; 
int h, w, n;
int sumd;

bool isvalid(int x, int y) {
    return x < h && y < w && x >= 0 && y >= 0 && !visited[x][y] && !rockmap[x][y];
}

void dfs(int x, int y, int dist, string path) {
    if (dist == sumd) {
        res.push_back(path); // 找到一条路径，加入结果
        return;
    }

    // 尝试向下移动
    if (isvalid(x + 1, y)) {
        visited[x + 1][y] = true;
        dfs(x + 1, y, dist + 1, path + 'D');
        visited[x + 1][y] = false; // 回溯
    }
    // 尝试向左移动
    if (isvalid(x, y - 1)) {
        visited[x][y - 1] = true;
        dfs(x, y - 1, dist + 1, path + 'L');
        visited[x][y - 1] = false; // 回溯
    }
    // 尝试向右移动
    if (isvalid(x, y + 1)) {
        visited[x][y + 1] = true;
        dfs(x, y + 1, dist + 1, path + 'R');
        visited[x][y + 1] = false; // 回溯
    }
    // 尝试向上移动
    if (isvalid(x - 1, y)) {
        visited[x - 1][y] = true;
        dfs(x - 1, y, dist + 1, path + 'U');
        visited[x - 1][y] = false; // 回溯
    }
}

int main() {
    cin >> h >> w >> n;
    sumd = ceil((h * w - n) / 2.0); 

    memset(rockmap, 0, sizeof(rockmap));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        rockmap[x][y] = true;
    }

    visited[0][0] = true;
    dfs(0, 0, 1, ""); 

    sort(res.begin(),res.end());
    cout<<res[0];
}