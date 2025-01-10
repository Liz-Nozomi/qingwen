#include <bits/stdc++.h>
using namespace std;

bool mi[10][10];
int n,m,k;
bool visited[10][10];

int step=0;
bool avaliablepath=false;
bool isvalid(int x,int y){
    return x>=0 and x<n and y>=0 and y<m and mi[x][y]==0 and visited[x][y]!=1;
}

//0,0 到 n-1,m-1
void DFS(int x,int y){
    if(x==n-1 and y==m-1 and step==k){
        avaliablepath=true;
        return;
    }
    visited[x][y]=true;
    step++;

    if(isvalid(x+1,y)) DFS(x+1,y);
    if(isvalid(x,y+1)) DFS(x,y+1);
    if(isvalid(x,y-1)) DFS(x,y-1);
    if(isvalid(x-1,y)) DFS(x-1,y);

    visited[x][y]=false;
    step--;
}


int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            bool temp;
            cin>>temp;
            mi[i][j]=temp;
        }
    }
    DFS(0,0);
    cout<<(avaliablepath?"Yes":"No");
}