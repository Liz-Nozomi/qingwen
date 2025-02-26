#include <bits/stdc++.h>
using namespace std;

int main(){
    register int n;
    cin>>n;

    bool yue[1000100];
    yue[1] = 1;
    yue[n] = 1;
    int sum = 0;
    sum+=1;sum+=n;

    for(register int i=2;i<=sqrt(n);i++){
        if(n % i == 0){
            register int temp = n/i;
            if(!yue[i]){
                sum += i;
            }
            if(!yue[temp]){
                sum+=temp;
            }
            yue[i] = 1;
            yue[temp] = 1;

            
        }

        
    }
   

    cout<<sum;
}