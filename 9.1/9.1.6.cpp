#include <bits/stdc++.h>
using namespace std;
int b[1000];

int BFS(vector<pair<int,int> > &v,int idx){
    queue<int> q;
    q.push(idx);
    int cnt = 0;
    
    while(!q.empty()){
        int len=q.size();
        for(int i=0;i<len;i++){
            auto temp = q.front();
            q.pop();
            b[temp] = cnt;
            if(v[temp].first!=-1){
                q.push(v[temp].first);
            }
            if(v[temp].second!=-1){
                q.push(v[temp].second);
            }
        }
        cnt++;

    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(pair<int,int>(a,b));


    }
    BFS(v,0);
    
}