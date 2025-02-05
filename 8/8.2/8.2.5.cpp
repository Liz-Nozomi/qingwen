#include <bits/stdc++.h>
using namespace std;
int mat[200][200];
bool used[200][200];
int n,m;
int dirx[8]={0,0,1,-1,0,0,2,-2};
int diry[8]={1,-1,0,0,2,-2,0,0};

bool isValid(int cx,int cy,int x,int y){
    
    return x>=0 and x<n and y>=0 and y<m and used[x][y]==false and mat[x][y] == 0 and mat[cx+(x-cx)/2][y] == 0 and mat[x][cy+(y-cy)/2] == 0;
    
}

int BFS(int x,int y){
    queue<pair<int,int> > q;
    q.push(pair<int,int>(x,y));
    used[x][y]=true;
    int step = 0;

    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){

        
            auto temp = q.front();
            q.pop();
            int currentX=temp.first;
            int currentY=temp.second;
            
            if(currentX == n-1 and currentY == m-1){
                return step;
            }

            for(int i=0;i<8;i++){
                if( isValid( currentX,currentY,currentX+dirx[i],currentY+diry[i] ) ){
                q.push(pair<int,int> (temp.first+dirx[i],temp.second+diry[i]));
                used[temp.first+dirx[i]][temp.second+diry[i]] = true;
            }
        }
    }
        step++;
    }
    return -1;
}

int main(){
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    int res = BFS(0,0);
    
    cout<<res;
}