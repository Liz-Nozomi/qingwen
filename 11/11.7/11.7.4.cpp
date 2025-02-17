#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,V;
    cin>>n>>V;
    int w[1010];
    
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    

    int dp[1010][1010];//维护方案数，dp[i][v] 表示到第i件物品，得到体积为v的方案数
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int vol = 0;vol <= V;vol++){
            dp[i][vol] = dp[i-1][vol];
            if(w[i] <= vol){
                dp[i][vol] = (dp[i-1][vol - w[i]] + dp[i][vol]) % 10007;
            }
        }
    }
    cout<<dp[n][V];
}