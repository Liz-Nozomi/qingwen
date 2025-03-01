#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;

}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n+1);
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }

    int dp[1020][2];//i0 互质 i1 不互质
    for(int i=1;i<=n;i++){
        dp[i][0] = 1;
        dp[i][1] = 1;
    }

    

    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(gcd(nums[i],nums[j]) == 1){//huzhi
                dp[i][0] = max(dp[i][0],dp[j][1] +1);
            }else{
                dp[i][1] = max(dp[i][1],dp[j][0] +1);

            }
        }
    }
    int maxl = 0;
    for(int i=1;i<=n;i++){
        if(dp[i][1] > maxl){
            maxl = dp[i][1];
        }
        if(dp[i][0] > maxl){
            maxl = dp[i][0];
        }
    }
    cout<<maxl;

}