#include <bits/stdc++.h>
using namespace std;
vector<int> tree[10000];

int DFS(int u,int pre,int n,int &mindiff){
    int cnt = 1;
    for(int i=0;i<tree[u].size();i++){
        int v = tree[u][i];
        if(v == pre){
            continue;
        }
        cnt += DFS(v,u,n,mindiff);

    }
    mindiff = min(mindiff,abs(cnt - (n-cnt)));
    return cnt;
}


int main(){
    int n;
    cin>>n;

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        tree[a-1].push_back(b-1);
        tree[b-1] .push_back(a-1);
    }//邻接表完成存储
    int mindiff = INT_MAX;
    DFS(0,-1,n,mindiff);
    cout<<mindiff;

}