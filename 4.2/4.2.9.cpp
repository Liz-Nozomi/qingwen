#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    
    map<int,int> seta;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        seta[temp]++;
    }
    vector<int> res;

    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        if(seta[temp]!=0){
            res.push_back(temp);
        }
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i];
        if(i<res.size()-1) cout<<" ";
    }
}