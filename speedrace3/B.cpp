#include <bits/stdc++.h>
using namespace std;

void dijkstra(int n,vector<vector< pair<int,int> > > &graph,vector<int> &dist){
    priority_queue<pair<int,int>, vector< pair<int,int> > ,greater<pair<int,int> > >pq;
    dist[1] = 0;
    pq.push(make_pair(0,1));

    while(!pq.empty()){
        auto cp = pq.top().second;
        auto dst = pq.top().first;

        pq.pop();

        if(dst > dist[cp]){
            continue;
        }
        for(auto it:graph[cp]){
            int np = it.second;
            int d = it.first;

            if(dist[cp] + d < dist[np]){
                dist[np] = dist[cp] + d;
                pq.push(make_pair(dist[np],np));
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector< pair<int,int> > > graph(n+1);//距离，节点编号
    for(int i=0;i<m;i++){
        int from,to,dist;
        cin>>from>>to>>dist;
        graph[from].push_back(make_pair(dist,to));
        graph[to].push_back(make_pair(dist,from));

    }
    vector<int> dist(n+1,INT_MAX);

    dijkstra(n,graph,dist);


    for (int i = 2; i <= n; ++i) {
        cout << dist[i];
        if (i < n) cout << " ";
    }

}