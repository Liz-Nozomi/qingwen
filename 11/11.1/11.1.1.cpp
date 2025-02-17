#include <bits/stdc++.h>
using namespace std;
long long dp[100000];

long long F(int n){
    if(n == 1 or n == 2){
        return 1;
    }
    else if(dp[n] != -1) return dp[n];
    else{
        dp[n] = (F(n-1)+F(n-2))%10007;
        return dp[n];
    }

}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<100000;i++){
        dp[i] = -1;
    }
    cout<< (F(n));

}