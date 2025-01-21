#include <bits/stdc++.h>
using namespace std;

void combineandoutput(vector<int> &nums1,vector<int> &nums2){
    int p1=0,p2=0;
    while(p1<nums1.size() and p2<nums2.size()){
        if(nums1[p1]<=nums2[p2]){
            cout<<nums1[p1];
            cout<<" ";
            p1++;
        }
        else{
            cout<<nums2[p2];
            cout<<" ";
            p2++;
        }
    }
    for(int i=p1;i<nums1.size();i++){
        cout<<nums1[i];
        if(i<nums1.size()-1){cout<<" ";}
    }
    for(int i=p2;i<nums2.size();i++){
        cout<<nums2[i];
        if(i<nums2.size()-1){cout<<" ";}

    }

}


int main(){
    int n,m;
    vector<int> nums1,nums2;
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

    combineandoutput(nums1,nums2);
}