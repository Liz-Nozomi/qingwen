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

    cout<<q.front()<<" "<<q.back();
}