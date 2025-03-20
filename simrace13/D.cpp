#include <bits/stdc++.h>
using namespace std;
vector<long long> t5nums;
vector<pair<int,int> > ranges;
long long shortest = LONG_MAX;

void generate_35_nums(int len,string s,int sz){
    if(len == sz){
        t5nums.push_back(stoll(s));
        return;
    }
    generate_35_nums(len+1,s+'3',sz);
    generate_35_nums(len+1,s+'5',sz);
    
}

bool isvalid(int l,int r,int k){
    //l and r are all index and limited to less than the smallest range
    //k is operations limit
    int opcnt = 0;
    for(auto it:ranges){
        long long itl = it.first;
        long long itr = it.second;
        if(t5nums[l] >= itl and t5nums[r] <= itr) continue;
        opcnt += min(abs(itl - t5nums[l]),abs(itr-t5nums[r]));
    }

    if(opcnt <= k){
        return true;

    }else{
        return false;
    }

    
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int sz=1;sz<=12;sz++) generate_35_nums(0,"",sz);
    sort(t5nums.begin(),t5nums.end());
    t5nums.erase(unique(t5nums.begin(), t5nums.end()), t5nums.end()); // 去重

    for(int i=0;i<n;i++){
        long long lf,rt;
        cin>>lf>>rt;
        ranges.push_back(make_pair(lf,rt));
        shortest = min(shortest,rt-lf);
    }

    int lr = 0;
    
    for(int l=0;l<t5nums.size();l++){
        int r = l;
        while(t5nums[r] - t5nums[l] <= shortest and r < t5nums.size()){

            if(isvalid(l,r,k)){
                lr = max(lr,r-l+1);
                r++;
            }else{
                break;
            }
        }
    
    }
    cout<<lr;


}