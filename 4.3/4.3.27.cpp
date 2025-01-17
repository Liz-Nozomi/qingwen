#include <bits/stdc++.h>
using namespace std;
int n,k;
vector< vector<int> > res;
vector<int> line,sr;

void DFS(int idx,int currentcount){
    if(currentcount == k){
        res.push_back(line);
        return;
    }
    if(idx == n){
        return;
    }
    DFS(idx+1,currentcount);
    line.push_back( sr[idx] );
    DFS(idx+1,currentcount+1);
    line.pop_back();



}



int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        sr.push_back(temp);
    }

    DFS(0,0);

    sort(res.begin(),res.end());
    
    //output
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