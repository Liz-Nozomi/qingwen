#include <bits/stdc++.h>
using namespace std;

bool cmp(int &a,int &b){
    return a>b;
}


int main(){
    int n;
    cin>>n;
    vector<int> score;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        score.push_back(temp);
    }
    sort(score.begin(),score.end(),cmp);
    
    int prev=-1;
    for(int i=0;i<n;i++){
        if(score[i]!=score[i-1]){
            prev=i;
            cout<<score[i]<<" "<<i+1<<endl;}
        else if(score[i]==score[i-1]){
            
            cout<<score[prev]<<" "<<prev+1<<endl;
        }
    }
}