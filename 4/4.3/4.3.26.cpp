#include <bits/stdc++.h>
using namespace std;
int n,k;
vector< vector<int> > res;
vector<int> line;

void DFS(int currentnum,int currentcount){
    if(currentcount == k){
        res.push_back(line);
        return;
    }
    if(currentnum == n+1){
        return;
    }
    DFS(currentnum+1,currentcount);
    line.push_back(currentnum);
    DFS(currentnum+1,currentcount+1);
    line.pop_back();



}



int main(){
    cin>>n>>k;
    DFS(1,0);
    sort(res.begin(),res.end());
    for(auto it:res){
        int t=0;
        for(auto it2:it){

            cout<<it2;
            t++;
            if(t<it.size()){
                cout<<" ";
            }
        }
        cout<<endl;
    }
}