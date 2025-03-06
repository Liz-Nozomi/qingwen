#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > starmap;
bool visited[205][205];

int n,m;

int dirx[4] = {1,0,-1,0};
int diry[4] = {0,1,0,-1};

bool isvalid(int x,int y){
    return x>=0 and x<n and y>=0 and y<m;
}

int bfs(int x,int y){
    //cout<<"called"<<x<<" "<<y<<endl;
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    int sum = 0;
    bool haveblackhole = false;

    while(!q.empty()){
        int sz = q.size();
        for(int layer = 0;layer < sz;layer++){
            auto temp = q.front();
            q.pop();
            visited[temp.first][temp.second] = true;
            sum += starmap[temp.first][temp.second];
            //cout<<sum<<endl;
            for(int d = 0;d < 4;d++){
                int tx = temp.first + dirx[d];
                int ty = temp.second + diry[d];

                if(isvalid(tx,ty)){

                    if(starmap[tx][ty] !=0 and !visited[tx][ty]){
                        if(starmap[tx][ty] == -1){
                            haveblackhole = true;
                        }
                        q.push(make_pair(tx,ty));
                        visited[tx][ty] = true;


                    }
                }
            }
        }
    }
    return (haveblackhole?0:sum);
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        vector<int> stars;

        for(int j=0;j<m;j++){
            int t;
            cin>>t;
            stars.push_back(t);
        }
        starmap.push_back(stars);
    }
    int maxn = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(starmap[i][j] != 0 and starmap[i][j] != -1 and !visited[i][j]){
                maxn = max(maxn,bfs(i,j));
            }
        }
    }
    cout<<maxn;
}

