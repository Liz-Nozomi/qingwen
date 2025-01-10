#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> db;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        db.push_back(temp);
    }
    string aim;
    cin>>aim;


    int rm=aim.length();

    map<int,int> appendi;

    for(auto &it:db){
        it.erase(0,rm);
        if(it==""){
            appendi[0]=1;
        }else{
        int temp=stoi(it);
        appendi[temp]=1;
        }
    }
    int flag=0;
    for(int i=0;i<n;i++){
        if(appendi[i]==0){
            flag=1;
            cout<<aim<<to_string(i);
        }    

    }
    if(flag==0){
        cout<<aim<<to_string(appendi.size());
    }
    

}