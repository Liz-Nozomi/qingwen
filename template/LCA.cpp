#include <bits/stdc++.h>
using namespace std;
#define LOGN 20
vector<int> tree[100010];//a tree also called graph
int father[100010][LOGN];//n,logn
int depth[100010];
bool visited[100010];

void dfs(int root){
    stack<pair<int,int> > s;//for node and depth
    s.push(pair<int,int>(root,0));
    father[root][0] = -1;
    depth[root] = 0;

    visited[root] = true;

    while(!s.empty()){
        auto currentnode = s.top();
        s.pop();
        
        int node = currentnode.first;
        int d = currentnode.second;

        for(int i=1;i<LOGN;i++){
            if(father[node][i] != -1){
                father[node][i] = father[father[node][i-1]][i-1];
            }
        }
        for(int child:tree[node]){
            if(!visited[child]){
                father[child][0] = node;
                depth[child] = d+1;
                visited[child] = true;
                s.push(pair<int,int>(child,d+1));
            }
        }
    }   
}

int lca(int x,int y){
    if(depth[x] < depth[y]){
        swap(x,y);
    }
    for(int i=LOGN -1;i>=0;i--){
        if(depth[x] - (1<<i) >= depth[y]){
            x = father[x][i]; 

        }
    }

    if(x == y){
        return x;
    }
    for(int i=LOGN-1;i>=0;i--){
        if(father[x][i] != father[y][i]){
            x = father[x][i];
            y=  father[y][i];
        }
    }
    return father[x][0];
}


int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u] .push_back(v);
        tree[v] .push_back(u);
    }

    dfs(0);

    for(int i=0;i<m;i++){
        int p,q;
        cin>>p>>q;
        cout<<lca(p,q)<<endl;
    }
}