#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,V;
    cin>>n>>V;
    int w[1010];
    int c[1010];
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }

    int dp[1010][1010];//维护价值，dp[i][ways][v] 表示前i件物品能塞进体积v的背包
    int cnt[1010][1010];

    memset(dp, 0, sizeof(dp));



    for (int v = 0; v <= V; v++) {
        cnt[0][v] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int vol = 0;vol <= V;vol++){
            if(vol >= w[i]){
                dp[i][vol] = max( dp[i-1][vol], dp[i-1][vol-w[i]]+c[i]);
                if(dp[i][vol] == dp[i-1][vol]){
                    cnt[i][vol] = cnt[i-1][vol];
                }
                if(dp[i][vol] == dp[i-1][vol-w[i]]+c[i]){
                    cnt[i][vol] = (cnt[i][vol] + cnt[i-1][vol-w[i]]) % 10007;
                }
            }
            else{
                dp[i][vol] = dp[i-1][vol];
                cnt[i][vol] = cnt[i-1][vol];
            }
        }
    }
    cout<<dp[n][V]<<" "<<cnt[n][V];
}