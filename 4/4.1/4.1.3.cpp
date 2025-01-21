#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> num;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        num.push_back(temp);
    }

    sort(num.begin(),num.end());

    for(int i=0;i<n;i++){
        cout<<num[i];
        if(i<n-1){cout<<" ";}
    }
    

}