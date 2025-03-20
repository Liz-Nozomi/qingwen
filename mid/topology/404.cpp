#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int to;
    int weight;
    Edge(int _to,int _weight){
        to = _to;
        weight = _weight;

    }
};

struct Vertice{
    int in;
    int out;

};

int main(){
    int n,m;
    cin>>n>>m;
    vector< vector<Edge> > graph(n);
    vector< Vertice> vertices(n);

    for(int i=0;i<m;i++){
        int from,to,weight;
        cin>>from>>to>>weight;
        graph[from].push_back( Edge(to,weight));
        vertices[from].out++;
        vertices[to].in++;
    }

    

}