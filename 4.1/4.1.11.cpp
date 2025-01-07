#include <bits/stdc++.h>
using namespace std;

bool cmp(int &a,int &b){
    return a>b;
}

int findsame(vector<int> &score,int begin,int n){
    int i=begin;
    while(score[i]==score[i+1]){
        i++;
    }
    if(i<n){
    return i;}
    else return n;    
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
        
        if(score[i]!=score[i+1]){
            cout<<score[i]<<" "<<i+1<<endl;}
        else if(score[i]==score[i+1]){
            
            int j=findsame(score,i,n-1);
            //cout<<j<<"hahaha"<<endl;
            for(int temp=i;temp<=j;temp++){
                cout<<score[j]<<" "<<j+1<<endl;
            }
            i=j;
            
        }
    }
}
