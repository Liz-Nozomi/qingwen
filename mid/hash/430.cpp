#include <bits/stdc++.h>
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
    int n;
    cin>>n;
    unordered_set<ll> uniqueHashes;
    vector<string> strings(n);

    for(int i=0;i<n;i++){
        cin>>strings[i];

        ll hashV = computehash(strings[i]);
        uniqueHashes.insert(hashV);
    }
    cout<<uniqueHashes.size();
}