#include <bits/stdc++.h>
using namespace std;

string A(int t){
    if(t==0){
        return "我的小鲤鱼";
    }else{
        return "抱着"+A(t-1)+"的我";
    }

}

int main(){
    int n;
    cin>>n;
    string s="吓得我抱起了"+A(n);
    cout<<s;
}