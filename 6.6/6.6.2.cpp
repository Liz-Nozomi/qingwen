#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    priority_queue<int> q;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        q.push(temp);
    }

    for(int i=0;i<k;i++){
        q.pop();
    }

    if(q.empty()){
        cout<<"empty priority queue";
    }else{
        cout<<q.top();
    }
}