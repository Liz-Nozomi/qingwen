#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,V;
    cin>>n>>V;
    int w[1000];
    int c[1000];
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }

    int dp[1000][1000];//维护价值，dp[i][v] 表示前i件物品能塞进体积v的背包
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int vol = w[i];vol <= V;vol++){
            dp[i][vol] = max( dp[i-1][vol], dp[i][vol - w[i]] + c[i]);

        }
    }
    cout<<dp[n][V];
}