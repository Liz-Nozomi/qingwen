#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n,0);
    for(int i=0;i<k;i++){
        v.pop_back();
    }
    cout<<v.size();

}