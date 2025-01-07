#include <bits/stdc++.h>
using namespace std;

//设定met(i)为在第i级阶梯时的上楼方法数量
//vector<int> met;

int findmet(int n){
    if(n==1){
        return 1;
    }
    else if(n==2){
        return 2;
    }
    else return(findmet(n-1)+findmet(n-2));
}

int main(){
    int t;
    cin>>t;
    cout<<findmet(t);
}