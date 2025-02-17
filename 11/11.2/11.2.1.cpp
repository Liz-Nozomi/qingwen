#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int dp[100001],nums[100001];
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }

    dp[1] = nums [1];
    int m = dp[1];
    for(int i=2;i<=n;i++){
        dp[i] = max( dp[i-1]+nums[i], nums[i] );
        if(dp[i] > m) m = dp[i];

    }
    cout<<m;
    
}