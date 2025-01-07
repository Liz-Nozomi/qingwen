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
    //cout<<seta[2];
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        seta[temp]--;
    }

    for(auto it=seta.begin();it!=seta.end();){
        if(it->second==0){
            it=seta.erase(it);

        }
        else ++it;

    }
    vector<int> res;

    for(pair<int,int> it:seta){
        for(int t=0;t < it.second;t++){
            res.push_back(it.first);
        }
        
    }
    for(int k=0;k<res.size();k++){
        cout<<res[k];
        if(k<res.size()-1) cout<<" ";
    }

}
