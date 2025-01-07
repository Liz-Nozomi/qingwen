#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> arr;
    string wd;
    while(cin>>wd){
        arr.push_back(wd);
    }
    int n=arr.size();
    for(int i=0;i<n;i++){
        arr[i][0]=toupper(arr[i][0]);
        cout<<arr[i];
        if(i!=n-1){
            cout<<" ";
        }
    }
}