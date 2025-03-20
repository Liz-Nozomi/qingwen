#include <bits/stdc++.h>
using namespace std;

int findpathcnt(int n,int k,int a,int b){
    vector<int> dp(k+1,0);
    dp[0] = n;
    
}

int main(){
    int q;
    cin>>q;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<q;i++){
        int n,k,a,b;
        cin>>n>>k>>a>>b;

        findpathcnt(n,k,a,b);
    }
}