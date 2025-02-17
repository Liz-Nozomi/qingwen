#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    //dp[i][j] 表示s1的第i号位和s2的第j号位前相同的位；
    
    int dp[1000][1000];//dp是长度量，dp是一个最优化方法，所以我们的目标只是优化量
    for(int i=0;i<s1.length();i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<s2.length();j++){
        dp[0][j] = 0;
    }


    for(int i=1;i<=s1.length();i++){
        for(int j=1;j<=s2.length();j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] +1;
            }
            else{
                dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout<<dp[s1.length()-1][s2.length()-1];
    
}