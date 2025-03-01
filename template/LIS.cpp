#include <bits/stdc++.h>
using namespace std;


int getLIS(const vector<int> &a,int n){
    //It is a dp function
    //time complexity O(n^2)
    if(n == 0)return 0;
    vector<int> dp(n+1,1);
    int LIS = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j] <= a[i]){
                dp[i] = max(dp[j] +1,dp[i]);
            }
                            
        }
        LIS = max(LIS,dp[i]);
    }
    return LIS;
}