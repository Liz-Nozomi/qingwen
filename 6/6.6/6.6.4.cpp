#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        q.push(temp);
    }
    cout<<q.top();
}