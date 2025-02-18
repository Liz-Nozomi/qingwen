#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int matrix[105][105];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    int dp[105][105];
    dp[0][0] = matrix[0][0];
    for(int i=1;i<m;i++){
        dp[0][i] = dp[0][i-1] + matrix[0][i];

    }
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][0] + matrix[i][0];

    }
    //dp[i][j] = max(dp[i-1][j]+mat[i][j],dp[i][j-1] + mat[i][j])
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j] = max(dp[i-1][j]+matrix[i][j],dp[i][j-1] + matrix[i][j]);
        }
    }
    cout<<dp[n-1][m-1];
}