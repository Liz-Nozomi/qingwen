#include <bits/stdc++.h>
using namespace std;
int n,k;
map<int,int> res;
int tempsum;
vector<int> bonus;

void DFS(int index){
    if(tempsum > k)return;
    if(index == n){
        res[tempsum]++;
        return;
    }

    DFS(index+1);

    tempsum+=bonus[index];
    DFS(index+1);
    tempsum-=bonus[index];



}


int main(){

    cin>>n>>k;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        bonus.push_back(temp);
    }

    DFS(0);

    cout<<res[k];

}