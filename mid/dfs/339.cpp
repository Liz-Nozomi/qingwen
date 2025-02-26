#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k1,k2;
    cin>>n>>k1>>k2;

    vector<int> l(n+1,-1);
    vector<int> r(n+1,-1);

    vector<int> father(n+1,-1);

    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i];
        father[l[i]] = i;
        father[r[i]] = i;


    }

    
    vector<int> fa1;
    vector<int> fa2;
    while(father[k1] !=-1){
        fa1.push_back(father[k1]);
        k1 = father[k1];
    }
    while(father[k2] !=-1){
        fa2.push_back(father[k2]);
        k2 = father[k2];
    }

    reverse(fa1.begin(),fa1.end());
    reverse(fa2.begin(),fa2.end());

    
    stack<int> res;
    for(int i=0;i<min(fa1.size(),fa2.size());i++){
        if(fa1[i] == fa2[i]){
            res.push(fa1[i]);
        }
    }
    cout<<res.top();



}