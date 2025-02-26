#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<pair<int,int> > mat(n*n+1);

    register bool flag = 0;//to left
    int num = 1;

    for(register int y=n-1;y>=0;y--){

        if(flag == 0){
            for(register int x=0;x<n;x++){
                mat[num] = pair<int,int> (y,x);
                num++;
                
            }
            flag = 1;
            continue;
        }

        if(flag == 1){
            for(register int x=n-1;x>=0;x--){
                mat[num] = pair<int,int> (y,x);
                num++;
            }
            flag = 0;
            continue;
        }
    }


    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int temp;
        cin>>temp;
        cout<<mat[temp].first<<" "<<mat[temp].second<<endl;
    }
}