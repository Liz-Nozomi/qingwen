#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int currentfloor = 0;
    int upfloor = 0;
    int downfloor = 0;

    for(int i=0;i<n;i++){
        int tgtf;
        cin>>tgtf;
        if(tgtf > currentfloor){
            upfloor += (tgtf - currentfloor);
            currentfloor = tgtf;
        }
        else{
            downfloor += (currentfloor - tgtf);
            currentfloor = tgtf;
        }
    }
        cout<<upfloor * 6 + downfloor * 4 + n * 5;
    
}