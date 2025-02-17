#include <bits/stdc++.h>
using namespace std;
int mat[200][200];
int visited[200]; 


void BFS(int idx,int n){
    queue<int> q;
    q.push(idx);

    int dist = 0;
    while(!q.empty()){
        int sz = q.size();
        for(int i=0;i<sz;i++){
            int temp = q.front();
            q.pop();

            if(visited[temp] == -1){
                visited[temp] = dist;
            }

            for(int j=0;j<n;j++){
                if(mat[temp][j] != 0 and visited[j] == -1 ){
                    q.push(j);
                }
            }


        }
        dist++;
    }
}

int main() {
    int n,m,s;
    cin >> n >> m>>s;

    //Initialize adj mat
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = 0;
        }
        visited[i] = -1;
    }


    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        mat[x][y] = 1;  // 有向图
        mat[y][x] = 1; // 如果是无向图，需要添加这行
    }
    BFS(s,n);
    for(int i=0;i<n;i++){
        cout<<visited[i];
        if(i < n-1) cout<<" ";
    }
}