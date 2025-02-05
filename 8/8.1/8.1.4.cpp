#include <bits/stdc++.h>
using namespace std;


int mi[10][10];
int n,m;
bool visited[10][10];
vector< pair<int,int> > db,res;

int mn=-INT_MAX; 

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int maxd=4;

bool isvalid(int x,int y){
    return x>=0 and x<n and y>=0 and y<m and visited[x][y]!=1;
}

//0,0 到 n-1,m-1
void DFS(int x,int y,int currentsum){
    

    if(x==n-1 and y==m-1){
        if(currentsum>mn) {
            mn=currentsum;
            res=db;
        }
        return;
    }
    visited[x][y]=true;
    //cout<<"loop here"<<x<<"  "<<y<<endl;
    
    for(int i=0;i<maxd;i++){
        int nextx=x+dx[i];
        int nexty=y+dy[i];
        //cout<<"dfsed"<<x<<y<<endl;
        //int tempsum=currentsum+mi[x][y];
        if(isvalid(nextx,nexty)){
            db.push_back(pair<int,int> (nextx,nexty));
            DFS(nextx,nexty,currentsum+mi[nextx][nexty]);
            db.pop_back();
        }
    }
    visited[x][y]=false;


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
    db.push_back(pair<int,int> (0,0));

    //vector< pair <int,int> > res;
    DFS(0,0,mi[0][0]);
    //cout<<mn<<endl;
    //cout<<res.size();
    for(auto it:res){
        cout<<it.first+1<<" "<<it.second+1<<endl;
    }
}