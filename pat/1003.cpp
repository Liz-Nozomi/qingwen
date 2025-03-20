#include <bits/stdc++.h>
using namespace std;
struct road{
    int to;
    int length;
    road(int _to,int _length){
        to = _to;
        length = _length;
    }
};
int main(){
    int n,m,c1,c2;
    cin>>n>>m>>c1>>c2;
    vector<int> city(n);
    for(int i=0;i<n;i++){
        cin>>city[i];
    }
    vector< vector<road> > graph(n);
    for(int i=0;i<m;i++){
        int from,to,len;
        cin>>from>>to>>len;
        graph[from].push_back(road(to,len));
        graph[to].push_back(road(from,len));
    }

    int dp1[505][505];//从a到b最短路数量
    
}