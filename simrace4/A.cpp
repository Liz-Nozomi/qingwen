#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){return a>b;}

int main(){
    int n,k;
    cin>>n>>k;

    priority_queue<int,vector<int> ,decltype(&cmp)> pq(cmp);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        pq.push(temp);
    }

    while(k > 0){
        int top1 = pq.top();
        pq.pop();
        int top2 = pq.top();
        if(k >= top2 - top1 +1){
            k-= top2 - top1 +1;
            top1 = top2+1;
            pq.push(top1);
            
        }else{
            top1 += k;
            k=0;
            pq.push(top1);
        }

    }
    int pro = 1;
    while(!pq.empty()){
        pro *= pq.top();
        pq.pop();
    }
    cout<<pro;
}