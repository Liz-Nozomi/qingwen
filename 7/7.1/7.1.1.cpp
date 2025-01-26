#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string oper;
        int num;
        cin>>oper;
        if(oper == "push"){
            cin>>num;
            s.push(num);
        }
        if(oper == "pop"){
            if(!s.empty()){
                auto k=s.top();
                cout<<k<<endl;
                s.pop();
            }
            else cout<<"-1"<<endl;
        }
    }

}