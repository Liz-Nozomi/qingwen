#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin>>s;
    int n=s.size();
    map<char,int> m;
    for(int i=0;i<n;i++){
        m[s[i]]++;
    }
    for(pair<char,int> it:m){
        cout<<it.first<<" "<<it.second<<endl;
    };
}
