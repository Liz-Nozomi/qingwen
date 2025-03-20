#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;

    vector< vector<int> > a(n,vector<int> (m,0));
    for(int i=0;i<=m-k;i++){
        for(int j=0;j<=n-k;j++){//方块
            for(int x=i;x<i+k;x++){
                for(int y=j;y<j+k;y++){
                    //cout<<x<<" "<<y<<endl;
                    a[y][x]++;
                }
            }


        }
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum += a[i][j];
        }
    }
    cout<<sum;
}   