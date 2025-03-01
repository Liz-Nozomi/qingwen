#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> num1(n+1);
    vector<int> num2(n+1);


    for(int i=1;i<=n-1;i++){
        cin>>num1[i];
    }
    for(int i=1;i<=n-1;i++){
        cin>>num2[i];
    }

    vector<int> dp(n+1,-1);
    dp[1] = 0;

    for(int i=1;i<=n-1;i++){
        if(dp[i] != -1){
            if(i + num1[i] <= n) {
                if(dp[i + num1[i]] != -1){
                    dp[i + num1[i]] = min(dp[i] +1,dp[i + num1[i]]);
                }else{
                    dp[i + num1[i]] = dp[i]+1;
                }

            }
            if(i + num2[i] <= n) {
                if(dp[i + num2[i]] != -1){
                    dp[i + num2[i]] = min(dp[i] +1,dp[i + num2[i]]);
                }else{
                    dp[i + num2[i]] = dp[i]+1;
                }
            }
        }
    }

    cout<<dp[n];

}