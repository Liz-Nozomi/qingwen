#include <bits/stdc++.h>
using namespace std;
bool rockmap[110][110];
bool visited[110][110];

string tres;

int h,w,n;
int sumd;

bool isvalid(int x,int y){
    return x<h and y<w and x>=0 and y>=0 and !visited[x][y] and !rockmap[x][y];
}
void dfs(int x,int y,int dist,string path){
    if(dist == sumd){
        //path.pop_back();
        tres = path;
        return;
    }


    if(isvalid(x+1,y)){

        visited[x+1][y] = true;
        path.push_back('D');
        dfs(x+1,y,dist+1,path);
        if(!tres.empty()) return;
        visited[x+1][y] = false;//huisu
        path.pop_back();

    }
    if(isvalid(x,y-1)){

        visited[x][y-1] = true;
        path.push_back('L');
        dfs(x,y-1,dist+1,path);
        if(!tres.empty()) return;
        visited[x][y-1] = false;//huisu
        path.pop_back();

    }
    if(isvalid(x,y+1)){

        visited[x][y+1] = true;
        path.push_back('R');
        dfs(x,y+1,dist+1,path);
        if(!tres.empty()) return;
        visited[x][y+1] = false;//huisu
        path.pop_back();
    }
    if(isvalid(x-1,y)){

        visited[x-1][y] = true;
        path.push_back('U');
        dfs(x-1,y,dist+1,path);
        if(!tres.empty()) return;
        visited[x-1][y] = false;//huisu
        path.pop_back();

    }
 
}

int main(){
    cin>>h>>w>>n;
    sumd = ceil((h*w-n)/2.0);


    for(int i=0;i<110;i++){
        for(int j=0;j<110;j++){
            rockmap[i][j] = false;
            visited[i][j] = false;
        }
    }//init

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        rockmap[x][y] = true;
    }
    visited[0][0] = true;
    dfs(0,0,1,"");//x,y,distance
    
    cout<<tres;
}