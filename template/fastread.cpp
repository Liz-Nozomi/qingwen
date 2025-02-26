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
    n = in();
    cout<<n;
}
