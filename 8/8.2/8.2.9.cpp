#include <bits/stdc++.h>
using namespace std;

int mat[200][200];
bool used[200][200];
int res[200][200]; // 用于存储每个点到起点的最短距离

int n, m;

int dirx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int diry[8] = {2, -2, 2, -2, 1, -1, 1, -1};

bool isValid(int x, int y,int d) {
    bool t = ( x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 0 && used[x][y] == false);
    if(d == 0 or d == 2){
        return t and mat[x-dirx[d]][y-diry[d]+1] == 0;
    }else if(d == 1 or d == 3){
        return t and mat[x-dirx[d]][y-diry[d]-1] == 0;
    }else if(d == 4 or d == 5){
        return t and mat[x-dirx[d]+1][y-diry[d]] == 0;

    }else{
        return t and mat[x-dirx[d]-1][y-diry[d]] == 0;
    }
}

void BFS(int x,int y) { 
    queue<pair<int, int> >  q;
    q.push(pair<int,int>(x,y));
    used[x][y] = true;
    res[x][y] = 0;

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        int currentX = temp.first;
        int currentY = temp.second;

        for (int d = 0; d < 8; d++) {
            int newX = currentX + dirx[d];
            int newY = currentY + diry[d];
            if (isValid(newX, newY,d)) {
                q.push(pair<int,int>(newX,newY));
                used[newX][newY] = true;
                res[newX][newY] = res[currentX][currentY] + 1; // 保存每个点到起点的距离
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int x,y;
    cin>>x>>y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat[i][j] = 0;
        }
    }
    int bl;
    cin>>bl;
    for(int i=0;i<bl;i++){
        int tx,ty;
        cin>>tx>>ty;
        mat[tx-1][ty-1] = -1;
    }

    // 初始化结果矩阵为 -1，表示不可达
    memset(res, -1, sizeof(res));
    memset(used, false, sizeof(used));

    
    BFS(x-1,y-1);
    

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