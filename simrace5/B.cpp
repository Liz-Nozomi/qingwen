#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a.begin(),a.end());

    int maxlen = 1;
    int templen = 1;
    for(int i=1;i<n;i++){
        if(a[i-1] == a[i]){

        }else if(a[i-1]+1 == a[i]){
            templen++;
        }else{
            templen = 1;
        }
        maxlen = max(maxlen,templen);
    }

    cout<<maxlen;
}