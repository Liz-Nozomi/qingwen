#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        q.push(temp);
    }
    cout<<q.top();
}