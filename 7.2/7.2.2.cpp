#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    queue<int> q;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        q.push(temp);


    }
    while(q.size()>1){
        int a1=q.front();
        q.pop();
        int a2=q.front();
        q.pop();
        int a3=a1+a2;
        q.push(a3);
    }
    cout<<q.front();
}