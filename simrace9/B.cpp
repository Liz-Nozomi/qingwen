#include <bits/stdc++.h>
using namespace std;
vector<int> int_to_bit(int n){
    vector<int> bits(32,0);
    for(int i=0;i<32;i++){
        bits[i] = (n>>i) & 1;
    }
    //reverse(bits.begin(),bits.end());

    return bits;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> k_bit = int_to_bit(k);
    vector< vector<int> > nums(n);

    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums[i] = int_to_bit(num);
        //cout<<nums[i][31];
    }
    int res = 0;

    for(int i=0;i<k_bit.size();i++){
        int zerocnt = 0;
        int onecnt = 0;

        //int rnds = 0;
        for(auto it:nums){
            if(it[i] == 0){
                zerocnt++;
            }
            else{
                onecnt++;
            }
        }

        if(k_bit[i] == 1){
            res += zerocnt;
        }
        else if(k_bit[i] == 0){
            if (onecnt == n) {
                res += 1;
            }
        }


    }
    cout<<res;

}