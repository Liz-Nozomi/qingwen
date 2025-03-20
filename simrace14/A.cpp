#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int cnt1 = 0;//ji
    int cnt2 = 0;//ou
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(temp % 2 == 1){
            cnt1 ++;
        }else{
            cnt2++;
        }

    }

    if(cnt1 % 2 == 0){
        //总和是偶数
        cout<<cnt2;
    }else{
        cout<<cnt1;
    }
 
}