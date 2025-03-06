#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> sticks(n);
    int maxl = 0;
    for(int i=0;i<n;i++){
        cin>>sticks[i];
        if(sticks[i] > maxl) maxl = sticks[i];
    }

    int left = 0;
    int right = maxl;

    while(left < right){
        int mid = (left + right +1)/2;
        int stickcount = 0;

        for(int i=0;i<n;i++){
            stickcount += sticks[i] / mid;

        }

        if(stickcount < k){
            right = mid-1;
        }else{
            left = mid;
        }


    }
    cout<<left;

}