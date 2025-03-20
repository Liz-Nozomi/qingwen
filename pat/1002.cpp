#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    map<int,float> poly;
    cin>>n;
    for(int i=0;i<n;i++){
        int base;
        float step;
        cin>>base>>step;
        poly[base] += step;
    }
    int m;

    cin>>m;
    for(int i=0;i<m;i++){
        int base;
        float step;
        cin>>base>>step;
        poly[base] += step;
    }
    for (auto it = poly.begin(); it != poly.end();) {
        if (abs(it->second) < 1e-6) { // Check if coefficient is approximately zero
            it = poly.erase(it);
        } else {
            ++it;
        }
    }
    
    cout<<poly.size()<<" ";
    
    int cnt = 0;
    for(auto it = poly.rbegin();it != poly.rend();it++){
        cout<<it->first<<" "<<fixed<<setprecision(1)<<it->second;
        cnt++;
        if(cnt < poly.size()){
            cout<<" ";
        }
    }
}