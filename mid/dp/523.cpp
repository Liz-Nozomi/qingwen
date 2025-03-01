#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n+1);

    
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    //dp[i][01] 代表以i结尾的序列,第二位0代表不删除当前，1代表删除当前
    int dp[10010][2];

    dp[1][0] = a[1];
    dp[1][1] = 0;
    //序号从1开始
    int res = INT_MIN;
    for(int i=2;i<=n;i++){
        dp[i][0] = max(dp[i-1][0]+a[i],a[i]);
        dp[i][1] = max(dp[i-1][0],dp[i-1][1] + a[i]);
        if(res<dp[i][0]) res=dp[i][0];
        if(res<dp[i][1]) res=dp[i][1];
    }
    cout<<res;
}