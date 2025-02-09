#include <bits/stdc++.h>
using namespace std;
vector<int> res;
void MRLsearch(vector<pair<int,int> > &v,int root){
    if(root == -1){
        return;
    }
    res.push_back(root);
    MRLsearch(v,v[root].first);
    MRLsearch(v,v[root].second);



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
    MRLsearch(v,0);
    int temp = 0;
    for(auto it:res){
        cout<<it;
        temp++;
        if(temp < res.size()){
            cout<<" ";
        }
    }
}