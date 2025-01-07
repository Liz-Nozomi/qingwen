#include <bits/stdc++.h>
using namespace std;

int facto(int s){
    if(s==0){
        return 1;
    }
    else{
        return(s*facto(s-1));
    }
}

int main(){
    int n;
    cin>>n;
    cout<<facto(n);
}