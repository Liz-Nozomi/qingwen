#include <bits/stdc++.h>

using namespace std;
int F(int n,int depth) {
    for(int i=0;i<4*(depth-1);i++){
        cout<<" ";
    }
    cout<<"n="<<n<<endl;
    //输出当前递归深度;
    if (n <= 2) {
        return 1;
    } else {
        return F(n - 1,depth+1) + F(n - 2,depth+1);

    }
}

int main(){
    int n;
    cin>>n;
    F(n,1);
}