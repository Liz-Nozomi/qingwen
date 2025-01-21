#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
int idx;
void binsearch(int n){
    idx=-1;
    int left=0,right=n-1;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(nums[mid] %2 == 0){
            right = mid-1;
            if(mid < idx or idx == -1)idx=mid;
        }else left = mid+1;
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

    
    binsearch(n);
    cout<<idx;

}