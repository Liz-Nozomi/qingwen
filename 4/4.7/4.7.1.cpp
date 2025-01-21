#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums,presum;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);

    }
    presum.push_back(nums[0]);
    for(int i=1;i<n;i++){
        presum.push_back(presum[i-1]+nums[i]);
    }
    
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int temp;
        cin>>temp;
        cout<<presum[temp-1]<<endl;
    }

}