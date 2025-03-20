#include <bits/stdc++.h>
using namespace std;
struct edge{
    int to;
};
int main(){
    int n,m,k;//站点，管道，佛头
    cin>>n>>m>>k;

    vector<int> head(k);
    vector < vector<edge> > graph(n);
    for(int i=0;i<k;i++){
        cin>>head[i];
    }
    for(int i=0;i<m;i++){
        edge e,e2;
        
        cin>>e2.to>>e.to;

        e2.to--;
        e.to--;
        graph[e2.to].push_back(e);
        graph[e.to].push_back(e2);
    }

    queue<int> q;
    vector<int> res(n,-1);

    for(auto it:head){
        q.push(it-1);
        res[it-1] = 0;
    }
    int time = 0;
    
    

    while(!q.empty()){
        time++;
        int sz = q.size();
        for(int i=0;i<sz;i++){
            int tpo = q.front();
            q.pop();
            for(auto edges:graph[tpo]){
                if(res[edges.to] == -1){
                    q.push(edges.to);
                    res[edges.to] = time;
                }
            }


        }
    }
    for(auto it:res){
        cout<<it<<endl;
    }
    

}