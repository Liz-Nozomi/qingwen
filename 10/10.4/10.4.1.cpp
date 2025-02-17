#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int to,weight;
    Edge(int _to,int _weight){
        to = _to;
        weight = _weight;
    }
};

vector<int> dijkstra(int start,vector< vector<Edge> > &graph){
    int n = graph.size();
    vector<int> dist(n,INT_MAX);
    dist[start] = 0;

    priority_queue< pair<int,int>, vector< pair<int,int> > ,greater< pair<int,int> > > pq;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();
        auto u = temp.second;
        auto d = temp.first;

        if(d > dist[u]) continue;

        for(auto edge: graph[u]){//每一个点的边
            int vert = edge.to;
            int weig  = edge.weight;
            if(dist[u] + weig < dist[vert]){
                dist[vert]=dist[u]+weig;
                pq.push(make_pair(dist[vert],vert));
            }
        }
    }
    return dist;
}

int main(){
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    vector< vector<Edge> > graph(n);


    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(Edge(v,w));
        graph[v].push_back(Edge(u,w));
    }

    auto res = dijkstra(s,graph);
    cout<<(res[t]!=INT_MAX?res[t]:-1);



}