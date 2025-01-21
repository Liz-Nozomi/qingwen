#include <bits/stdc++.h>
using namespace std;

vector<int> findintersection(vector<int> &s1,vector<int> &s2){
    int p1=0,p2=0;
    vector<int> ret;
    while(p1 < s1.size() and p2 < s2.size()){
        if(s1[p1] == s2[p2]){
            ret.push_back(s1[p1]);
            p1++;
            p2++;
        }
        else if(s1[p1] < s2[p2]){
            p1++;
        }
        else{p2++;}
    }
    return ret;
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

    auto res=findintersection(nums1,nums2);
    int temp=0;
    for(auto it:res){
        temp++;
        cout<<it;
        if(temp<res.size()){cout<<" ";}
    }


}
