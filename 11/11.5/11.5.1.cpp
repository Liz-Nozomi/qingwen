#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int dp[1000][1000];
    int maxlen = 1;
    for(int i=1;i<=s.length();i++){
        dp[i][i] = 1;
        if(s[i-1] == s[i]){
            dp[i][i+1] = 2;
            maxlen = 2;
        }

    }
    for(int len = 3;len <= s.length();len++){
        for(int i=1;i+len-1<=s.length();i++){
            int j = i+len-1;
            if(s[i] == s[j] and dp[i+1][j-1] == 1)
            dp[i][j] = 1;
            maxlen = len;
        }
    }
    cout<<maxlen;
}