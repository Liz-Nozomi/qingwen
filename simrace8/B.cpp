#include <bits/stdc++.h>
using namespace std;
//TLE but high enough
int main(){
    int n,k;
    cin>>n>>k;
    priority_queue<int ,vector<int>,greater<int> >pq; 
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        pq.push(t);
    }
    while(k > 0){
        int temp = pq.top();
        pq.pop();
        int secondsmall = pq.top();
        if(secondsmall - temp +1 <= k){
            k -= (secondsmall - temp +1);
            temp = secondsmall+1;
            pq.push(temp);
        }else{
            pq.push(temp + k);
            k=0;
        }
    }
    cout<<pq.top();
}