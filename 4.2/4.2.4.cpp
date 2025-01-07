#include <bits/stdc++.h>
using namespace std;



int main(){
    int n,m;
    cin>>n>>m;
    vector<int> target;
    vector<int> searchv;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        target.push_back(temp);

    }
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        searchv.push_back(temp);

    }

    map<int,int> res;
    for(int it:searchv){
        for(int element:target){

        
            if(it==element) res[it]++;
        }
    }
    for(int i=0;i<m;i++){
        cout<<res[searchv[i]];
        if(i<m-1) cout<<" ";
    }
}