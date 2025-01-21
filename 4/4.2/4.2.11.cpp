#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    
    map<int,int> seta;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        seta[temp]=1;
    }
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        seta[temp]=0;
    }
    int count=0;
    for(auto it=seta.begin();it!=seta.end();){
        if(it->second==0){
            it=seta.erase(it);

        }
        else ++it;

    
    }
        for(pair<int,int> it:seta){
        cout<<it.first;
        count++;
        if(count<seta.size()){
            cout<<" ";
        }
    }


}
