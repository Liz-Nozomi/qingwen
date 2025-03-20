#include <bits/stdc++.h>
using namespace std;

int getnum(vector<int> &a,int qi){
    bool existed[1000010];
    memset(existed,false,sizeof(bool));

    int maxn = -1;
    for(int i=0;i<qi;i++){
        existed[a[i]] = true;    
        maxn = max(maxn,a[i]);
    }

    for(int i=0;i<=maxn+1;i++){
        if(existed[i] == false){
            return i;
        }
    }
}
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<q;i++){
        int qi;
        cin>>qi;

        cout<<getnum(a,qi)<<endl;
    }


}