#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> num;
    map<int,int> count;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        num.push_back(temp);

    }
    for(int it:num){
        //cout<<it<<endl;
        count[it]++;
    }
    //cout<<count.size()<<"hahaha"<<endl;
    for(pair <int,int> i:count){
        cout<<i.first<<" "<<i.second<<endl;
    }
}
