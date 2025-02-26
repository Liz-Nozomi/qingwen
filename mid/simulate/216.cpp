#include <bits/stdc++.h>
using namespace std;

int main(){
    register int n;
    cin>>n;

    bool yue[1000100];
    yue[1] = 1;
    yue[n] = 1;
    int cnt = 2;
    for(register int i=2;i<=sqrt(n);i++){
        if(n % i == 0){
            register int temp = n/i;
            if(!yue[i]){
                cnt++;
            }
            if(!yue[temp]){
                cnt++;
            }
            yue[i] = 1;
            yue[temp] = 1;

            
        }

        
    }
   
    int temp = 0;
    for(int i=1;i<=n;i++){
        if(yue[i]){
            cout<<i;
            temp++;
            if(temp < cnt){
                cout<<" ";
            }
        }
        
        
    }
}