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
    int res = 0;
    while(q.size() >1){
        int x = q.top();
        q.pop();
        int y=q.top();
        q.pop();
        q.push(x+y);
        res += x+y;
    }
    cout<<res;
}