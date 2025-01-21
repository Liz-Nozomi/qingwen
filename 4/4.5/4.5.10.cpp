#include <bits/stdc++.h>
using namespace std;
vector<int> nums;

int binsearch(int n,int tgt){
    int left=0,right=n-1;

    while(left <= right){
    int mid=left+(right - left)/2;
    if(nums[mid]==tgt){
        return mid;
    }
    else if (nums[mid]>=nums[0]){
        if(tgt >= nums[0] and tgt < nums[mid]){
            right=mid-1;
        }else{
            left=mid+1;
        }

    }
    else{
        if(tgt>nums[mid] and tgt<=nums[n-1]){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    }
    return -1;
}


int main(){
    int n,tgt;
    cin>>n>>tgt;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    cout<<binsearch(n,tgt);

}