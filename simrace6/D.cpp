#include <bits/stdc++.h>
using namespace std;
#define int long long
__attribute__((optimize("O2")))

struct Edge{
    bool avali = false;
    int d;//间隔
    int t;//耗时
};

Edge graph[1001][1001];

int get_time_consume(int from,int to,int currenttime){
    int d = graph[from][to].d;
    int t = graph[from][to].t;
    if(currenttime % d == 0){
        return t;
    }
    else{
        return d - (currenttime % d) + t;;
    }
}

int bfs(int start,int end,int n,int currenttime){
    //vector<bool> visited(n+1,false);
    queue<int> q;

    vector<int> dp(n+1,-1);
    dp[start] = currenttime;
    q.push(start);
    while(!q.empty()){
        int sz = q.size();
        for(int rep = 0;rep < sz;rep++){
        int tp = q.front();
        q.pop();


        for(int i=1;i<=n;i++){
            if(graph[tp][i].avali){
                if(dp[i] == -1){//未访问过
                    q.push(i);
                    dp[i] = dp[tp] + get_time_consume(tp,i,dp[tp]);
                }
                else if(dp[i] > dp[tp] + get_time_consume(tp,i,dp[tp])){
                    dp[i] = dp[tp] + get_time_consume(tp,i,dp[tp]);
                    q.push(i);

                }


            }
        }
    }

    }
    return dp[end];
}
#undef int
int main(){

    #define int long long 
    
    ios::sync_with_stdio(false);
    
    int n,m,a,b,c;
    cin>>n>>m>>a>>b>>c;



    for(int i=1;i<=m;i++){
        Edge e;
        int fr,t;
        cin>>fr>>t;
        e.avali = true;
        cin>>e.t>>e.d;
        graph[fr][t] = e;
        graph[t][fr] = e;


    }
    
    int t1 = bfs(a,b,n,0);
    //cout<<t1<<endl;
    if(t1 != -1){
        int t2 = bfs(b,c,n,t1);
        if(t2 != -1){
            cout<<t2;
        }else{
            cout<<-1;
        }
    }
    else{
        cout<<-1;
    }

    //俺寻思迪杰斯特拉是最快的，但是我忘了

}