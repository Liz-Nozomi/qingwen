#include <bits/stdc++.h>
using namespace std;

stack<int> s;
vector<int> currentSeq;

vector< vector<int> > res;
int n;


void DFS(int idx){
    if(idx > n and s.empty()){
        res.push_back(currentSeq);
        return;
    }
    if(idx <= n){
        s.push(idx);
        DFS(idx+1);
        s.pop();
    }
    if(!s.empty()){
        int topp = s.top();
        s.pop();
        currentSeq.push_back(topp);

        DFS(idx);

        currentSeq.pop_back();
        s.push(topp);
    }




}

int main(){
    cin>>n;
    DFS(1);

    sort(res.begin(),res.end());
    for(auto it:res){
        int temp=0;
        for(auto it2:it){
            cout<<it2;
            temp++;
            if(temp < it.size()) cout<<" ";

        }
        cout<<endl;
    }
}