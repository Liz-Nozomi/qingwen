#include <bits/stdc++.h>
using namespace std;
long long binaryPow(long long a,long long b){
    if(b == 0)return 1;
    if(b % 2 == 1){
        return a* binaryPow(a,b-1);
    }
    else{
        long long mul=binaryPow(a,b/2);
        return mul*mul;
    }
}
int main(){
    long long  a,b;
    cin>>a>>b;
    cout<<binaryPow(a,b);
    
}