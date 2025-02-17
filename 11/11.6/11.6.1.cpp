#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int to;
    int weight;
    Edge(){}
    Edge(int _to,int _weight){
        to = _to;
        weight = _weight;
    }
};

int graph[1000][1000];
int dp[1000];
int n;
int DP(int i){
    if(dp[i] > 0){
        return dp[i];
    }
    for(int j=0;j<n;j++){
        if(graph[i][j] != -1){
            dp[i] = max(dp[i],DP(j)+graph[i][j]);
        }
    }
    return dp[i];
}
int main(){
    int pointcount,edgecount;
    cin>>pointcount>>edgecount;
    n = pointcount;
    for(int i=0;i<pointcount;i++){
        for(int j=0;j<pointcount;j++){
            graph[i][j] = -1;
        }
    }

    for(int i=0;i<edgecount;i++){
        int from,to,weight;
        cin>>from>>to>>weight;
        graph[from][to] = weight;

    }   
    int maxlen=0;
    for(int i=0;i<n;i++){
        maxlen = max(maxlen, DP(i));    }
    cout<<maxlen;
    

}