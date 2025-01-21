#include <bits/stdc++.h>
using namespace std;
long long binaryPow(long long a,long long b,long long m){
    if(b == 0)return 1;
    if(b % 2 == 1){
        return a* binaryPow(a,b-1,m) % m;
    }
    else{
        long long mul=binaryPow(a,b/2,m);
        return mul*mul%m;
    }
}
int main(){
    long long  a,b,m;
    cin>>a>>b>>m;
    cout<<binaryPow(a,b,m);
    
}