#include <bits/stdc++.h>
using namespace std;
int mat[200][200];
bool used[200][200];
int n,m;
int dirx[4]={0,0,1,-1};
int diry[4]={1,-1,0,0};

bool isValid(int x,int y){
    return x>=0 and x<n and y>=0 and y<m and used[x][y]==false and mat[x][y] == 1;
}
void BFS(int x,int y){
    queue<pair<int,int> > q;
    q.push(pair<int,int>(x,y));
    used[x][y]=true;
    while(!q.empty()){
        auto temp = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            if(isValid(temp.first+dirx[i],temp.second+diry[i])){
                q.push(pair<int,int> (temp.first+dirx[i],temp.second+diry[i]));
                used[temp.first+dirx[i]][temp.second+diry[i]] = true;
            }
        }
    }

}

int main(){
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(used[i][j] == false and mat[i][j]==1){
                BFS(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt;
}