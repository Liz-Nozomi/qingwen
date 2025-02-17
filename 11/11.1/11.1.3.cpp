#include <bits/stdc++.h>
using namespace std;
int dp[100000];
int main(){
    int n;
    cin>>n;
    dp[n] = 1;
    dp[n-1] = 2;
    for(int i = n-2;i>=1;i--){
        dp[i] = (dp[i+1] + dp[i+2]) % 10007;
    }
    cout<<dp[1];
}