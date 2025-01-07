#include <bits/stdc++.h>
using namespace std;

bool isRev(string s){
    if(s.length()==1 or (s.length()==2 and s[0]==s[1])){
        return 1;
    }
    else if(s[0]==s[s.size()-1]){
        return isRev(s.substr(1,s.length()-2));}
    else return 0;

}
int main(){
    string sr;
    cin>>sr;
    
    cout<<((isRev(sr))?"Yes":"No");

}