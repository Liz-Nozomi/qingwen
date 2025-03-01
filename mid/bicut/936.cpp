#include <bits/stdc++.h>
using namespace std;

int main(){
    //二分来遍历长度

    int n,k,l;
    cin>>n>>k>>l;
    vector<int> segment(n);

    for(int i=0;i<n;i++){
        cin>>segment[i];
    }

    int left = 1;
    int right = l;
    int ans = 0;

    while(left <= right){
        int mid = left + (right - left) / 2;
        int count = 0;
        int last = 0;

        for(int i=0;i<n;i++){
            if(segment[i] - last >= mid){
                count++;
                last = segment[i];
                if(count >= k){
                    break;
                }
            }
        }

        if(count >= k and (l-last) >= mid){
            ans = mid;
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    cout<<ans;
}