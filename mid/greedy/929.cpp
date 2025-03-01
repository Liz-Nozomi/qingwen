#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    ll sum_delta = 0;
    for(int i=0;i<n;i++){
        sum_delta += abs(a[i] - b[i]);
        if(sum_delta > k){
            break;
        }
    }
    if(sum_delta > k){
        cout << "No";
    }
    else{
        if( (k - sum_delta) % 2 == 0 ){
            cout << "Yes";
        }
        else{
            cout << "No";
        }
    }
}