#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int zerocount=0;
    int paircount=0;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(temp == 0){
            zerocount++;
        }
        else if(temp ==1){
            paircount += zerocount;
        }
        
    }
    cout<<paircount;


}