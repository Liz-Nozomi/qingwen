#include <bits/stdc++.h>
using namespace std;

int main(){
    //dp[i]:成本
    int dp_r[10010],dp_y[10010],dp_b[10010];
    int a[10010],b[10010],c[10010];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }

    dp_r[1] = a[1];
    dp_y[1] = b[1];
    dp_b[1] = c[1];

    for(int i=2;i<=n;i++){
        dp_r[i] = min( dp_y[i-1] , dp_b[i-1] ) +a[i];
        dp_y[i] = min( dp_r[i-1] , dp_b[i-1] ) +b[i];
        dp_b[i] = min( dp_r[i-1] , dp_y[i-1] ) +c[i];

    }
    int temp = min(dp_r[n],dp_y[n]);
    cout<<min(temp,dp_b[n]);
}
