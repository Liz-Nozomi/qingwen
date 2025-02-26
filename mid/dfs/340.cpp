#include <bits/stdc++.h>
using namespace std;
vector<int> pathsum;

void dfs(int n,vector<int> &l,vector<int> &r,vector<int> &f,vector<int> &w){
    pathsum[n] += w[n];
    if(l[n] != -1){
        pathsum[l[n]] += pathsum[n];
        dfs(l[n],l,r,f,w);
    }
    
    if(r[n] != -1){
        pathsum[r[n]] += pathsum[n];
        dfs(r[n],l,r,f,w);
    }
    


}


int main(){
    int n;
    cin>>n;
    vector<int> w(n+1);
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    vector<int> l(n+1,-1);
    vector<int> r(n+1,-1);
    vector<int> father(n+1,-1);
    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i];
        father[l[i]] = i;
        father[r[i]] = i;

    }
    int root = -1;
    for(int i=0;i<n;i++){
        if(father[i] == -1){
            root = i;
        }
    }
    pathsum.resize(n+1,0);
    dfs(root,l,r,father,w);
    
    int summ = 0;
    for(int i = 0;i<n;i++){
        if(l[i] == -1 and r[i] == -1){
            summ += pathsum[i];
        }

    }
    cout<<summ;
    
}