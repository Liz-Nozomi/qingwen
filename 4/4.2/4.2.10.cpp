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
        seta[temp]=1;
    }
    int count=0;
    for(pair<int,int> it:seta){
        cout<<it.first;
        count++;
        if(count<seta.size()){
            cout<<" ";
        }
    }
}