#include <bits/stdc++.h>
using namespace std;

vector< pair<int,int> > twopointersearch(vector<int> &nums, int &n,int &k){
    int left=0,right=n-1;
    vector<pair<int,int> > ret;
    while(left < right){
        if(nums[left] + nums[right] == k){
            ret.push_back(pair<int,int>(left,right));
            left++;
            right--;
        }
        else if(nums[left]+nums[right]<k){
            left++;
        }
        else if (nums[left]+nums[right]>k){
            right--;
        }

    }
    return  ret;
}


int main(){
    int n,k;
    vector<int> nums;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    auto res=twopointersearch(nums,n,k);
    cout<<res.size();
}