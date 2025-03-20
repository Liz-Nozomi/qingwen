#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int to;
    int idx;
    Edge(int _to,int _idx){
        to = _to;
        idx = _idx;
    }
};

struct Vertice{
    int in=0;
    int out=0;
};

int main(){
    int n,m;
    cin>>n>>m;
    vector< vector<Edge> > graph(n);//n个顶点的边集
    vector<Vertice> vs(n);

    for(int i=0;i<m;i++){
        int from,to;
        cin>>from>>to;
        vs[from].out++;
        vs[to].in++;
        graph[from].push_back(Edge(to,i));
    }

    vector<bool> visited(n,false);
    vector<int> res;

    bool isring = false;
    int cyccount = 0;
    while(cyccount < n and !isring){
        cyccount++;
        
        for(int i=0;i<n;i++){
                if(vs[i].in == 0){
                    if(visited[i] == false){
                        visited[i] = true;
                    }else{
                        isring = true;
                        break;
                    }

                    res.push_back(i);
                    
                    for(auto it:graph[i]){
                        int t = it.to;
                        vs[t].in --;
                    }
                    break;//跳出这个for，回到while
                }

            
        }


    }
    cout<<(isring?"Yes":"No");

    
    
}