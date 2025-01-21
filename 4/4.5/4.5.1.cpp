#include <bits/stdc++.h>
using namespace std;
vector<int> nums;

int binsearch(int left,int right,int find){
    if(left > right){
        return -1;
    }
    int mid=left+(right-left)/2;
    if(nums[mid] == find){
        return mid;
    }else if(nums[mid] > find){
        return binsearch(left,mid-1,find);
    }else{
        return binsearch(mid+1,right,find);
    }
}

int main(){
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }

    cout<<binsearch(0,n-1,x);

}