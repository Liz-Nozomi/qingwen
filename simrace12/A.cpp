#include <bits/stdc++.h>
using namespace std;

int main(){
    long long s,e,k;
    cin>>s>>e>>k;
    long long cnt = 0;


    long long  mul;
    if(s % k == 0){
        mul = s/k;
    }else{
        mul = s/k+1;
    }

    long long maxn = e/k;

    cout<<maxn - mul+1;
}