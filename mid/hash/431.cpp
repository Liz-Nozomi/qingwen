#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;
typedef long long ll;

const ll P = 10000007 + 19;
const ll MOD = 1000000000 + 7;

ll computehash(const string &s){
    ll hash = 0;
    ll p_pow = 1;
    for(char c:s){
        hash = (hash +(c-'a' +1)*p_pow) % MOD;
        p_pow = (p_pow *P)%MOD;
    }
    return hash;
}


int main(){
    //暴力
    string s1,s2;
    cin>>s1;
    cin>>s2;
    
    if(s1.size() > s2.size()){
        string temp = s2;
        s2 = s1;
        s1 = temp;
    }
    unordered_set<ll> us;

    for(int l=0;l<s1.size();l++){
        for(int r=l;r<s1.size();r++){
            auto temp = computehash(s1.substr(l,r-l+1));
            us.insert(temp);
        }
    }

    int len = 0;
    for(int l=0;l<s2.size();l++){
        for(int r=l;r<s2.size();r++){
            auto ts = computehash(s2.substr(l,r-l+1));
            if(us.find(ts) != us.end()){
                len = max(len,r-l+1);
            }

        }
    }
    cout<<len;

}