#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    set< pair<int,int> > us;

    sort(nums.begin(),nums.end());
    do{
        for(int k=1;k<n-1;k++){
            //前k个,遍历k
            int u = 0;int v = 0;
            for(int i=0;i<k;i++){
                u = u*10+nums[i];
            }
            for(int i=k;i<n;i++){
                v = v*10+nums[i];
            }
            if(v < u) swap(u,v);
            us.insert(make_pair(u,v));

        }
    }while(next_permutation(nums.begin(),nums.end()));
    //cout<<endl;
    if(n == 2 and k == 0){
        cout<<0<<" "<<0;
        return 0;
    }
    for(auto it:us){
        if(it.first * it.second == k){
            cout<<it.first<<" "<<it.second;
            break;
        }
    }

}