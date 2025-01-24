#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n,k);
    int temp=0;
    for(auto it:v){
        cout<<it;
        temp++;
        if(temp < n)cout<<" ";
    }
}