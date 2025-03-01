#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int sum = (n+1) *n /2;
    if(sum % 2 == 1){//无法二分
        cout<<0;
    }
    else{
        int tgt = sum / 2;
        vector<long long> dp(tgt+1,0);
        dp[0] = 1;
        for(int i=1;i<n;i++){
            for(int j=tgt;j>=i;j--){
                dp[j] = (dp[j] + dp[j-i]) % (1000000007);
            }
        }

        cout<<dp[tgt];

    }


    

}
