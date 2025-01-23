#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    map<char,int> mp;
    cin>>n;
    for(int i=0;i<n;i++){
        char tc;
        int ti;
        cin>>tc>>ti;
        mp[tc]=ti;

    }
    
    char fnd;
    cin>>fnd;
    mp.erase(fnd);
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    



}