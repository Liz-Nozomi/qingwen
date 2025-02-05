#include <bits/stdc++.h>
using namespace std;

int mi[10][10];
int n,m;
bool visited[10][10];

int mn=-INT_MAX; 

bool isvalid(int x,int y){
    return x>=0 and x<n and y>=0 and y<m and visited[x][y]!=1;
}

//0,0 到 n-1,m-1
void DFS(int x,int y,int currentsum){
    if(x==n-1 and y==m-1){
        currentsum+=mi[x][y];
        if(currentsum>mn) mn=currentsum;
        return;
    }
    //cout<<"loop here"<<x<<"  "<<y<<endl;
    visited[x][y]=true;
    currentsum += mi[x][y];

    if(isvalid(x+1,y)) DFS(x+1,y,currentsum);
    if(isvalid(x,y+1)) DFS(x,y+1,currentsum);
    if(isvalid(x,y-1)) DFS(x,y-1,currentsum);
    if(isvalid(x-1,y)) DFS(x-1,y,currentsum);

    visited[x][y]=false;
    currentsum -= mi[x][y];


}


int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int temp;
            cin>>temp;
            mi[i][j]=temp;
        }
    }
    DFS(0,0,0);
    cout<<mn;
}