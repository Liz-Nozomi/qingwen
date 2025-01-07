#include <bits/stdc++.h>
using namespace std;

string rvs(string s){
    if(s.length()==1){
        return s;
    }
    else{
        return(rvs(s.substr(1))+s[0]);
    }
}


int main(){
    string sr;
    cin>>sr;
    string res=rvs(sr);
    cout<<res;
}