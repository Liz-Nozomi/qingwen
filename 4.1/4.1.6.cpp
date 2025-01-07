#include <bits/stdc++.h>
using namespace std;
bool cmp(string &a,string &b){
    return a>b;
}
int main(){
    int n;
    cin>>n;
    vector<string> chars;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        chars.push_back(temp);
    }
    sort(chars.begin(),chars.end(),cmp);
    for(string word:chars){
        cout<<word<<endl;
    }
    
}