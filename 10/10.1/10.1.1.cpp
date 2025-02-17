#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;

    cin>>n>>m;
    int adj[1000][1000];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    int in[1000];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            in[i] += adj[i][j];
        }
    }
    for(int i=0;i<n;i++){
        cout<<in[i];
        if(i<n-1){
            cout<<" ";
        }
    }

}