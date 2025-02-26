#include <bits/stdc++.h>
using namespace std;
string equalfindbig(string &a,string &b,int i){
    int sz = a.size();
    if(i == sz){
        return "a = b";
    }
    for(int j=i;j<=sz;j++){
        if(a[j] == b[j]){
            return equalfindbig(a,b,j+1);
        }

        else if(a[j] > b[j]){
            return "a > b";
        }
        else{
            return "a < b";
        }
    }
}

int main(){
    string a,b;
    cin>>a>>b;
    if(a.size() > b.size()){
        cout<<"a > b";

    }
    else if(a.size() < b.size()){
        cout<<"a < b";
    }
    else{
        cout<<equalfindbig(a,b,0);
    }
}