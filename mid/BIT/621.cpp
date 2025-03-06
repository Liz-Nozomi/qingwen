#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b;
    map<int,int> new_idx;
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    b = a;
    sort(a.begin(),a.begin()+n);
    new_idx[a[0]] = 0;

    for(int i=1;i<n;i++){
        if(a[i] != a[i-1]){
            new_idx[a[i]] = new_idx[a[i-1]]+1;

        }
    }
    int temp = 0;
    for(auto it:b){
        cout<<new_idx[it];
        temp++;
        if(temp < b.size()){
            cout<<" ";
        }
    }
}