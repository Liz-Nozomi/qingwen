#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<string,int> res;

    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        res[temp]++;
   }

    int m;
    cin>>m;
    for(int i=0;i<n;i++){
        string temp2;
        cin>>temp2;
        cout<<res[temp2];
        if(i<n-1) cout<<" ";
        
    }
}