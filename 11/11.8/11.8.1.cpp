#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int dp[10010];//在第i个高台消耗的最小能量
    //dp[i] = min( dp[i-1] + abs(h(i)-h(i-1)), dp[i-2] balabala)
    int h[10010];
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }

    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);
    for(int i=3;i<=n;i++){
        dp[i] = min( dp[i-1] + abs(h[i]-h[i-1]), dp[i-2] + abs(h[i]-h[i-2]) );

    }
    cout<<dp[n];
}