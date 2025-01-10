#include <bits/stdc++.h>
using namespace std;

int findminbdf(int n,int m,vector<int> &Bn){
    sort(Bn.begin(),Bn.end());
    int min_diff=INT_MAX;
    for(int i=0;i<=n-m;i++){
        int cdf=Bn[i+m-1]-Bn[i];
        if(cdf<min_diff){
            min_diff=cdf;
        }
    }
    return min_diff;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<int> Bn;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        Bn.push_back(temp);

    }
    cout<<findminbdf(n,m,Bn);

}

    
