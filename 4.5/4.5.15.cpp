#include <bits/stdc++.h>
using namespace std;
vector<int> nums1,nums2;
pair<int,int> binsearch(int n,int m){
    int l1=0,r1=n-1;
    int l2=0,r2=m-1;
    int mid1=n,mid2=m;
    while(l1 <= r1 and l2 <= r2){
        
        mid1=l1 + (r1-l1)/2;
        mid2=l2 + (r2-l2)/2;
        if(nums1[mid1]>nums2[mid2]){
            r1=mid1-1;
            l2=mid2+1;
        }
        else {
            l1 = mid1+1;
            r2 = mid2-1;
        }
    }
    return pair<int,int>(mid1,mid2);
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums1.push_back(temp);
    }
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        nums2.push_back(temp);
    }
    auto tmp=binsearch(n,m);

    if((m+n)%2==0){
        cout<<fixed<<setprecision(1)<<(( static_cast<double>(nums1[tmp.first]) + nums2[tmp.second] ) /2)<<endl;
    }else{
        cout<<fixed<<setprecision(1)<<static_cast<double>(max(nums1[tmp.first],nums2[tmp.second]))<<endl;
    }


    //cout<<tmp.first<<" "<<tmp.second;

}