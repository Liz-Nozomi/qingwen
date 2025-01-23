#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    int temp=0;
    for(auto it:v){
        cout<<it;
        temp++;
        if(temp < n)cout<<" ";
    }
}