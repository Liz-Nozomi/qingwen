#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v1,v2;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v1.push_back(temp);
    }
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        v2.push_back(temp);

    }

    cout<< (v1<v2?"Yes":"No");
}