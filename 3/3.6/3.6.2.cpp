#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> arr;
    string wd;
    while(cin>>wd){
        arr.push_back(wd);
    }
    int n=arr.size();
    for(int i=n-1;i>=0;i--){
        cout<<arr[i];
        if(i!=0){
            cout<<" ";
        }
    }

}
