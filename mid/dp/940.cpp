#include <bits/stdc++.h>
using namespace std;
#define int long long
struct job{
    int D;
    int C;
    int S;
    job(){}
};

bool sort1(job a,job b){
    return a.D < b.D;
}
#undef int
int main(){
    #define int long long
    int n;
    cin>>n;
    vector<job> work(n+1);
    int Dimax = 0;

    for(int i = 1;i<=n;i++){
        cin>>work[i].D>>work[i].C>>work[i].S;        
        Dimax = max(Dimax,work[i].D);
    }

    sort(work.begin()+1,work.end(),sort1);

    vector<int> dp(Dimax+1,-1);//维护花费i时间时的盈利


    dp[0] = 0;

    for(int i=1;i<=n;i++){
        int D = work[i].D;
        int C = work[i].C;
        int S = work[i].S;


        for(int j=D;j>=C;j--){
            if(j-C>=0 and dp[j-C] != -1){
                dp[j] = max(dp[j],dp[j-C]+S);
            }

        }
    }
    
    int maxm = 0;
    for(int i=0;i<=Dimax;i++){
        if(dp[i] > maxm){
            maxm = dp[i];
        }
    }
    cout<<maxm;


}