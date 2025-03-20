#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n+1);
    vector<int> dp(n+1);
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    dp[0] = 0;

    int maxn = 0;

    vector<int> prev(n+1,-1);
    for(int i=1;i<=n;i++){
        prev[i] = i;
    }
    

    for(int i=1;i<=n;i++){
        if(dp[i-1]+ nums[i] >= nums[i]){
            dp[i] = dp[i-1] + nums[i];
            prev[i] = prev[i-1];
        }else{
            dp[i] = nums[i];
        }
        maxn = max(dp[i],maxn);
        
    }
    //cout<<prev[5];

    int i=0;
    //cout<<maxn<<" ";
    while(dp[i] != maxn){
        i++;
    }
    cout<<maxn<<" "<<prev[i]-1<<" "<<i-1<<endl;
}