#include <bits/stdc++.h>
using namespace std;
int n;
set<int> res;
int tempsum;
vector<int> bonus;

void DFS(int index){
    
    if(index == n){
        res.insert(tempsum);
        return;
    }

    DFS(index+1);

    tempsum+=bonus[index];
    DFS(index+1);
    tempsum-=bonus[index];



}


int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        bonus.push_back(temp);
    }

    DFS(0);
    int t=0;
    for(auto it:res){
        cout<<it;
        t++;
        if(t<res.size()) cout<<" ";
    }
}