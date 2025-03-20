#include<bits/stdc++.h>
using namespace std;
int in()
{
    int k=0,f=1;//f 符号
    char c=getchar();
    while(c<'0'||c>'9')//非数字扔了
    {
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        k=k*10 + (c-'0');
        c=getchar();
    }
    return k*f; // 别忘记标记的负数要乘进去
}

int main(){
    int n;
    n=in();


    vector<vector<vector<int > > > value(n, vector<vector<int>>(n, vector<int>(n)));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                value[i][j][k] = in();
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        long long result = 0;
        int l1,l2,l3,r1,r2,r3;
        l1=in();
        l2=in();
        l3=in();
        r1=in();
        r2=in();
        r3=in();
        l1--;
        l2--;
        l3--;
        r1--;
        r2--;
        r3--;
        for(int i=l1;i<=l2;i++){
            for(int j=l3;j<=r1;j++){
                for(int k=r2;k<=r3;k++){
                    result += value[i][j][k];
                }
            }
        }
        cout<<result<<"\n";
    }
    return 0;
}