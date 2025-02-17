#include <bits/stdc++.h>
using namespace std;
int mat[200][200];
bool used[200];
int weight[200];
int n,m;

void DFS(int idx,int &sum){
    used[idx] = true;
    sum += weight[idx];

    for(int i=0;i<n;i++){
        if(mat[idx][i] == 1 and !used[i] and i != idx){
            DFS(i,sum);
            
        }
    }
}

int main(){
    priority_queue< int> res;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j] = 0;

        }
        cin>>weight[i];
    }
    

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        mat[x][y] = 1;
        mat[y][x] = 1;
    }

    for(int i=0;i<n;i++){
        int sum = 0;
        if(!used[i]){
            DFS(i,sum);
            res.push(sum);
        }
    }
    cout<<res.top();



    
}