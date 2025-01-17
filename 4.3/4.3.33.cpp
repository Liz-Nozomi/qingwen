#include <bits/stdc++.h>
using namespace std;
int n,k;
map<int,int> res;
int tempsum;
vector<int> bonus;

vector<int> tempset;
map< vector<int> , int > existed;



void DFS(int index){
    if(tempsum > k)return;

    if(index == n){
        sort(tempset.begin(),tempset.end());
        if(existed[tempset]==0){
            res[tempsum]++;
            existed[tempset]=1;
            
        }
        return;
    }

    DFS(index+1);

    tempsum+=bonus[index];
    tempset.push_back(bonus[index]);
    DFS(index+1);
    tempset.pop_back();
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