#include<bits/stdc++.h>
using namespace std;
int mincut(string s){
    int n = s.length();
    if(n == 0){
        return 0;
    }
    vector< vector<bool> > is_rev(n,vector<bool>(n,false));
    for(int i=0;i<n;i++){
        is_rev[i][i] = true;
    }

    for(int len=1;len<n;len++){
        for(int i=0;i+len<n;i++){

            int j = i + len;

            if(len == 1){
                if(s[i] == s[j]){
                    is_rev[i][j] = true;
                }
            }

            else{
                is_rev[i][j] = is_rev[i+1][j-1] and (s[i] == s[j]);
            }
        }
    }//完成维护

    vector<int> dp(n);//i结尾的分割数量
    for(int i=0;i<n;i++){
        dp[i] = i+1;
    }

    for(int end = 1;end < n;end++){
        int start;
        bool flag = false;
        for(start = 0;start < end;start++){
            if(is_rev[start][end]){
                //cout<<start<<"here"<<endl;
                flag = true;
                break;
            }
        }
        if(flag){
            dp[end] = dp[start];
        }else{
            dp[end] = dp[end-1]+1;
        }
        
    }

    
    return dp[n-1];


}
int main(){
    string s;
    cin>>s;
    int a = mincut(s);
    cout<<a;
}