#include <bits/stdc++.h>
using namespace std;
char mat[200][200];
bool used[200][200];

int n,m;

int dirx[4]={0,0,1,-1};
int diry[4]={1,-1,0,0};

bool isValid(int x,int y){
    return x>=0 and x<n and y>=0 and y<m and (mat[x][y] == '.' or mat[x][y] == 'T') and used[x][y]==false;
}

int BFS(int x,int y,int endx,int endy){
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
            
            if(currentX == endx and currentY == endy){
                return step;

            }

            for(int d=0;d<4;d++){
                if(isValid(currentX+dirx[d],currentY+diry[d])){
                    q.push(pair<int,int> (temp.first+dirx[d],temp.second+diry[d]));
                    used[temp.first+dirx[d]][temp.second+diry[d]] = true;
            }
        }
    }
        step++;
    }
    return -1;
}

int main(){
    pair<int,int> stt,end;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
            if(mat[i][j] == 'S'){
                stt.first = i;
                stt.second = j;
                //cout<<i<<j<<endl;

            }
            if(mat[i][j] == 'T'){
                end.first = i;
                end.second = j;
                //cout<<i<<j<<endl;

            }
        }
    }
    memset(used, false, sizeof(used));

    int res = BFS(stt.first,stt.second,end.first,end.second);
    
    cout<<res;
}