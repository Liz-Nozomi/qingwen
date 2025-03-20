#include <bits/stdc++.h>
using namespace std;

int remember[110][110];
int getopcnt(vector< vector<bool> > &graph ,int x,int y){
    if(remember[x][y] != -1){
        return remember[x][y];
    }

    //x y 都是从0开始标号
    queue< pair<pair<int,int>,bool> > q;//ds:x,y,switchcount
    q.push(make_pair(make_pair(0,0),0));

    int min_switch = INT_MAX;
    while(!q.empty()){
        auto current = q.front();
        q.pop();
        int tx = current.first.first;
        int ty = current.first.second;
        int tc = current.second;

        if(tx == x and ty == y){
            min_switch = min(tc,min_switch);
        }
        if(tx + 1 <= x){
            if(graph[tx+1][ty]== 1 and graph[tx][ty]== 0){
                q.push(make_pair(make_pair(tx+1,ty),tc+1));
            }else{
                q.push(make_pair(make_pair(tx+1,ty),tc));

            }
        }
        if(ty+1 <= y){
            if(graph[tx][ty+1]==1 and graph[tx][ty] == 0){
                q.push(make_pair(make_pair(tx,ty+1),tc+1));
            }else{
                q.push(make_pair(make_pair(tx,ty+1),tc));

            }
        }


    }
    remember[x][y] = min_switch;
    return min_switch;

}

int main(){
    //方法：bfs整个图，统计最少的S和A切换数量
    for(int i=0;i<110;i++){
        for(int j=0;j<110;j++){
            remember[i][j] = -1;
        }
    }

    int h,w,q;
    cin>>h>>w>>q;
    vector< vector<bool> > graph(h);

    for(int i=0;i<h;i++){
        vector<bool> line;
        for(int j=0;j<w;j++){
            char temp;
            cin>>temp;
            if(temp == 'A'){
                line.push_back(1);
            }
            else{
                line.push_back(0);
            }

        }
        graph[i] = line;

    }

    for(int i=0;i<q;i++){
        int ix,iy;
        cin>>ix>>iy;
        cout<<getopcnt(graph,ix-1,iy-1)<<endl;
    }

}