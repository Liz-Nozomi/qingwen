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
        
    }
    int in[1000],out[1000];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            in[i] += adj[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            out[i] += adj[j][i];
        }
    }


    for(int i=0;i<n;i++){
        cout<<out[i]<<" "<<in[i]<<endl;
        
    }

}