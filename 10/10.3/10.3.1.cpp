#include <bits/stdc++.h>
using namespace std;
int mat[200][200];
bool used[200];
int n,m;

void DFS(int idx){
    
    for(int i=0;i<n;i++){
        if(mat[idx][i] == 1 and !used[i] and i != idx){
            used[i] = 1;
            DFS(i);
            
        }
    }



}

int main(){
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j] = 0;
        }
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        mat[x][y] = 1;
        mat[y][x] = 1;
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(!used[i]){
            DFS(i);
            cnt++;
        }

    }
    cout<<cnt;



    
}