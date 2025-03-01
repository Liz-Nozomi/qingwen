#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n+1);

    
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    //dp[i][01] 代表以i结尾的序列,第二位0代表无删除，1代表删一个，2代表两个
    int dp[10010][3];

    dp[1][0] = a[1];
    dp[1][1] = 0;
    
    dp[2][0] = a[1] + a[2];
    dp[2][1] = max(dp[1][0],dp[1][1] + a[2]);
    dp[2][2] = 0;


    //序号从1开始
    int res = INT_MIN;


    for(int i=3;i<=n;i++){
        dp[i][0] = max(dp[i-1][0]+a[i],a[i]);
        dp[i][1] = max(dp[i-1][0],dp[i-1][1] + a[i]);
        dp[i][2] = max(dp[i-1][2] + a[i],dp[i-1][1]);

        if(res<dp[i][0]) res=dp[i][0];
        if(res<dp[i][1]) res=dp[i][1];
        if(res<dp[i][2]) res=dp[i][2];
    }

    if(n == 1){
        res = max(0,a[1]);
    }
    else if(n == 2){
        res = max(0,max(a[1],max(a[2],a[1]+a[2])));

    }
    
    cout<<res;
}