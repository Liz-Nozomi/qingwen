#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int dp_iszero[10010];
    int dp_isnotzero[10010];
    //dp[i] 表示正好到第i个数结尾时，不连续出现两个0的序列数量。
    //dp_iszero[i] = dp_isnotzero[i-1]
    //dp_isnotzero[i] = dp_isnotzero[i-1] + dp_iszero[i-1] + 9;
    dp_iszero[1] = 1;
    dp_isnotzero[1] = 9;
    for(int i=2;i<=n;i++){
        dp_iszero[i] = dp_isnotzero[i-1];
        dp_isnotzero[i] = (dp_isnotzero[i-1] + dp_iszero[i-1]) * 9 % 10007;
    }
    cout<<(dp_iszero[n] + dp_isnotzero[n]) % 10007 ;
    

}