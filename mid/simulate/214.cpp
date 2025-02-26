#include <bits/stdc++.h>
using namespace std;

int main(){
    register int n;
    cin>>n;

    bool yue[1000100];
    yue[1] = 1;
    yue[n] = 1;

    for(register int i=2;i<=sqrt(n);i++){
        if(n % i == 0){
            yue[i] = 1;
            yue[n/i] = 1;
        }

        
    }
    int sum = 0;
    for(int i=1;i<=n;i++){
        if(yue[i]){
            sum++;
        }
    }

    cout<<sum;
}