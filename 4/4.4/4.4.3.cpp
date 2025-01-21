#include <bits/stdc++.h>
using namespace std;


int main(){
    int iszero=1;
    int a[10]={0};
    for(int i=0;i<10;i++){
        cin>>a[i];
        if(i != 0 and a[i]!= 0 ){
            iszero=0;
        }
    }
    string currentstr;
    for(int pointer=9;pointer>=0;pointer--){
        while(a[pointer]!=0){
            currentstr=currentstr + to_string(pointer);
            a[pointer]--;
        }
    }
    if(iszero == 1){
        cout<<0;

    }
    else cout<<currentstr;
}