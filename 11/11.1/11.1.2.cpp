#include <bits/stdc++.h>
using namespace std;
int towel[1000][1000],dp[1000][1000];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>towel[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        dp[n][i] = towel[n][i];
    }

    for(int i = n-1;i>=1;i--){
        for(int j=1;j<=n-1;j++){
            dp[i][j] = max(dp[i+1][j],dp[i+1][j+1])+towel[i][j];
        }
    }
    cout<<dp[1][1];

}