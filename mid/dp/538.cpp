#include <bits/stdc++.h>
using namespace std;
//俺寻思这玩意本地能跑
struct Edge{
    int to;
    int val;
    Edge(){}
};


int main(){
    int n,m;
    cin>>n>>m;
    vector< vector<Edge> > G(n+1);

    for(int i=1;i<=m;i++){
        int a;
        Edge e;
        cin>>a>>e.to>>e.val;

        G[a].push_back(e);
        //邻接表
    }
    
    vector<int> dp(n+1,0);//截止点i，有多少个权为1
    vector<int> from(n+1,-1);

    queue<int> q;
    q.push(1);
    dp[1] = 0;

    while(!q.empty()){
        int sz = q.size();
        for(int i=0;i<sz;i++){
            int tp = q.front();
            q.pop();
            for(auto it:G[tp]){
                q.push(it.to);
                if(it.val == 1){

                    if(dp[it.to] < dp[tp] + 1){
                        dp[it.to] = dp[tp] + 1;
                        from[it.to] = tp;
                    }
                    
                }
            }
        }
    }

    cout<<dp[n]<<endl;
    vector<int> path;
    path.push_back(n);


    int i = n;

    while(i != -1){
        if(from[i] != -1){
            path.push_back(from[i]);}
        i = from[i];
    }

    reverse(path.begin(),path.end());

    int cnt = 0;
    for(auto it:path){
        cout<<it;
        cnt++;
        if(cnt < path.size()){
            cout<<" ";
        }
    }
    
    
}