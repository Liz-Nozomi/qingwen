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
    vector<bool> used(n,false);
    vector<int> res;

    for(int i=0;i<n;i++){//n轮扫描


        for(int j=0;j<n;j++){
            if(vs[j].in == 0 and !used[j]){
                used[j] = true;
                res.push_back(j);
                for(auto it:graph[j]){
                    vs[it.to].in--;
                }
                break;
            }
        }
    }

    if(res.size() < n){
        cout<<"No"<<endl;
        cout<<n-res.size();
    }
    else{
        cout<<"Yes"<<endl;
        int temp = 0;
        for(auto it:res){
            cout<<it;
            temp++;
            if(temp < n){
                cout<<" ";
            }
        }

    }

}