#include <bits/stdc++.h>
using namespace std;

// 定义方向数组，表示上下左右四个方向
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

// 定义网格的大小
int n, m;

int grid[10][10];
int weight[10][10];
// 定义访问标记数组
bool visited[10][10];

// 定义结果变量
int result = INT_MIN;

//路径
//vector< pair<int,int> >path,res;

// 检查当前坐标是否有效
bool isValid(int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < m and !visited[x][y] and grid[x][y]!=1;
}

// DFS函数
void DFS(int x, int y, int currentSum) {
    // 标记当前节点为已访问
    visited[x][y] = true;
    //path.push_back(pair<int,int> (x, y));
    // 更新结果

    if (x == n - 1 && y == m - 1) {
        if (currentSum > result) {
            result = currentSum;
            //res = path;
        }
        }else{
    // 递归访问相邻节点
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (isValid(nextX, nextY)) {
            DFS(nextX, nextY, currentSum + weight[nextX][nextY]);
            
            }
        }
    }
    // 回溯，取消标记
    visited[x][y] = false;
    //path.pop_back();
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int temp;
            cin>>temp;
            grid[i][j]=temp;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int temp;
            cin>>temp;
            weight[i][j]=temp;
        }
    }

    DFS(0,0,weight[0][0]);
    cout<<result;
}