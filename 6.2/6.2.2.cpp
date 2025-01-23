#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;
    int n,fnd;
    cin>>n>>fnd;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        s.insert(temp);
    }

    auto it=s.find(fnd);
    if(it != s.end()){
        s.erase(it);
    }

    
    int temp=0;
    for(auto it:s){
        cout<<it;
        if(temp < s.size()-1){
            cout<<" ";
        }
        temp++;
    }
}