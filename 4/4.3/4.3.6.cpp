#include <bits/stdc++.h>
using namespace std;

int fib(int s){
    if(s==1 or s==2){
        return 1;
    }
    else{
        return fib(s-1)+fib(s-2);

    }
}
int main(){
    int n;
    cin>>n;
    cout<<
    fib(n);
}