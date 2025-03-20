#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    bool cl[100010];

    memset(cl,false,sizeof(bool));
    
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        cl[t] = true;
    }
    int min;
    for(int i=1;i<=100000;i++){
        if(cl[i] == false){
            min = i;
            break;
       }
    }

    int maxn;
    for(int i=100000;i>=1;i--){
        if(cl[i] == false){
            maxn = i;
            break;
        }
    }

    cout<<min<<" "<<maxn;
}