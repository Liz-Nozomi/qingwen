#include <bits/stdc++.h>
using namespace std;
vector<int> res;
void LRMsearch(vector<pair<int,int> > &v,int root){
    if(root == -1){
        return;
    }
    
    LRMsearch(v,v[root].first);
    
    LRMsearch(v,v[root].second);
    res.push_back(root);



}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(pair<int,int>(a,b));


    }
    LRMsearch(v,0);
    int temp = 0;
    for(auto it:res){
        cout<<it;
        temp++;
        if(temp < res.size()){
            cout<<" ";
        }
    }
}