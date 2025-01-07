#include <bits/stdc++.h>
using namespace std;

struct record{
    char character;
    int count;
    record(char _c,int _i){
        character=_c;
        count=_i;
    }
};

vector<record> rcd;

int main(){
    string ch;
    cin>>ch;
    int i=0,ipre=-1;
    for(i=0;i<ch.length();i++){
        if(ch[i]!=ch[i+1]){
            rcd.push_back(record(ch[i],i-ipre));
            ipre=i;
        }
    
    }
    for(int j=0;j<rcd.size();j++){
        cout<<rcd[j].character<<" "<<rcd[j].count<<endl;
    }

}