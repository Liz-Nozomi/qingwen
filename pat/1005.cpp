#include <bits/stdc++.h>
using namespace std;

vector<string> gethms(string s){
    vector<string> ret(3);
    auto pos1 = s.find(':');
    auto pos2 = s.find(':',pos1+1);
    string hh = s.substr(0,pos1);
    string mm = s.substr(pos1+1,pos2-pos1-1);
    string ss = s.substr(pos2+1);

}


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string id,intime,outtime;

        cin>>id>>intime>>outtime;

    }
}