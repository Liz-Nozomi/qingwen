#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
int istop(int idx){
    if(nums[idx-1] < nums[idx] and nums[idx] > nums[idx+1]){return 1;}//顶
    if(nums[idx-1] < nums[idx] and nums[idx] < nums[idx+1]){return 2;}//递增段
    if(nums[idx-1] > nums[idx] and nums[idx] > nums[idx+1]){return 3;}//递减段
   
}


int binsearch(int n){
    int left=0,right=n-1;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(istop(mid)==1){return mid;}
        else if(istop(mid)==2){left=mid+1;}
        else if(istop(mid)==3){right = mid-1;}
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    cout<<binsearch(n);

}