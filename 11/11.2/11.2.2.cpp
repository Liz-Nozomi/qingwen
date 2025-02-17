#include <bits/stdc++.h>
using namespace std;

struct sij{
    int s;
    int i;
    int j;
    sij(int _s,int _i,int _j){
        s=_s;i=_i;j=_j;
    }
    sij(){}
};
bool cmp(sij a, sij b) {
    if (a.i != b.i) {
        return a.i < b.i;
    } else {
        return a.j < b.j;
    }
}
int main(){
    int n;
    cin>>n;
    sij dp[100001],nums[100001];
    for(int i=1;i<=n;i++){
        cin>>nums[i].s;
    }

    dp[1] = nums[1];
    dp[1].i=1;
    dp[1].j=1;
    //vector<sij> v;
    int m = dp[1].s;

    //如果是转移来的，就记录前一个的左和自己右
    //如果是自己，就记录自己左和自己右
    for(int i=2;i<=n;i++){
        if(dp[i-1].s + nums [i].s >= nums[i].s){
            dp[i].s = dp[i-1].s+nums[i].s;
            dp[i].i=dp[i-1].i;
            dp[i].j=i;
            if(dp[i].s > m) m = dp[i].s;
        }
        else{
            dp[i].s=nums[i].s;
            dp[i].i = i;
            dp[i].j=i;
            if(dp[i].s > m) m = dp[i].s;

        }

    }
    vector<sij> res;
    for(int i=1;i<=n;i++){
        if(dp[i].s == m){
            res.push_back(dp[i]);
        }
    }
    sort(res.begin(),res.end(),cmp);
    cout<<res[0].s<<" "<<res[0].i<<" "<<res[0].j;

}