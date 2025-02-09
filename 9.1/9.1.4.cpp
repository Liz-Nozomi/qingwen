#include <bits/stdc++.h>
using namespace std;

vector<int> res;
void BFS(vector<pair<int,int> > &v,int idx){
    queue<int> q;
    q.push(idx);
    while(!q.empty()){
        for(int i=0;i<q.size();i++){
            auto temp = q.front();
            q.pop();
            res.push_back(temp);
            if(v[temp].first!=-1){
                q.push(v[temp].first);
            }
            if(v[temp].second!=-1){
                q.push(v[temp].second);
            }
        }
    }
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
    int temp = 0;
    for(auto it:res){
        cout<<it;
        temp++;
        if(temp < res.size()){
            cout<<" ";
        }
    }
}