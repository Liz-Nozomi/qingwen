#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int movd = 0;
    for(int i=1;i<s.size();i++){
        movd += abs(s[i] - s[i-1]);
    }
    cout<<movd;
}