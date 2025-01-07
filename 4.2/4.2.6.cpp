#include <bits/stdc++.h>
using namespace std;



int main(){

    string target;
    string searchs;

    cin>>target;
    cin>>searchs;   

    map<char,int> res;


    for(int it:searchs){
        if(find(target.begin(),target.end(),it)!=target.end()){
            res[it]=1;
            //cout<<it<<"hahaha"<<endl;
            }
    }
    for(int i=0;i<searchs.size();i++){
        cout<<res[searchs[i]];
        if(i<searchs.size()-1) cout<<" ";
    }
}