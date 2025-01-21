#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    priority_queue<int, vector<int> > maxHeap;    
    for(int i=0;i<k;i++){
        int temp;
        cin>>temp;
        maxHeap.push(temp);
    }
    for(int i=k;i<n;i++){
        int temp;
        cin>>temp;
        if(temp < maxHeap.top()){
            maxHeap.pop();
            maxHeap.push(temp);
        }
    }

    cout<<maxHeap.top();

}