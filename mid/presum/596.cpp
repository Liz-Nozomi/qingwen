#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    int l,r;
    cin>>n>>k;
    cin>>l>>r;

    vector<int> nums(n);
    int segsum = 0;
    vector<int> presum(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
        segsum += nums[i];
        if(i > 0){
            presum[i] = nums[i] + presum[i-1];
        }else{
            presum[i] = nums[i];
        }
    }

    l = l % n;
    r = r % n;
    int fullseg = r / n - l / n;

    int res = 0;

    if(l == r){
        res = fullseg * segsum;
    }else if(l > r){
        fullseg --;
        res = fullseg * segsum + presum[r] + (segsum - presum[l] + nums[l]);
    }else{
        res = fullseg * segsum + presum[r] - presum[l] + nums[l];
    }
    cout<<res;
}
