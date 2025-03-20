#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    reverse(a.begin(),a.end());
    
    int temp = 0;
    for(auto it:a){
        cout<<it;
        temp++;
        if(temp < a.size()){
            cout<<" ";
        }
    }
}