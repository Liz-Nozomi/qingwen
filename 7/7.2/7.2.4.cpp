#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    queue<int> q1,q2;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        q1.push(temp);
    }
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        q2.push(temp);
    }
    int cnt=0;
    while(!q1.empty() and !q2.empty()){
        if(q1.front() == q2.front()){
            q1.pop();
            q2.pop();

        }
        else{
            int temp;
            temp=q2.front();
            q2.pop();
            q2.push(temp);
        }
        cnt++;
    }
    cout<<cnt;
}