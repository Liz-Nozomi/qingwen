#include <bits/stdc++.h>
using namespace std;

int main(){
    int u,v,w,a,b,c,x;
    cin>>u>>v>>w>>a>>b>>c>>x;
    vector<int> ae(a);
    vector<int> be(b);
    vector<int> ce(c);

    vector<int> xe(x);
    for(int i=0;i<a;i++){
        cin>>ae[i];
    }
    for(int i=0;i<b;i++){
        cin>>be[i];
    }
    for(int i=0;i<c;i++){
        cin>>ce[i];
    }
    for(int i=0;i<x;i++){
        cin>>xe[i];
    }

    sort(ae.begin(),ae.end(),greater<int>());
    sort(be.begin(),be.end(),greater<int>());
    sort(ce.begin(),ce.end(),greater<int>());
    sort(xe.begin(),xe.end(),greater<int>());
    vector<int> res;
    for(int i=0;i<u;i++){
        res.push_back(ae[i]);
    }
    for(int i=0;i<v;i++){
        res.push_back(be[i]);
    }    
    for(int i=0;i<w;i++){
        res.push_back(ce[i]);
    }

    for(int i=0;i<x;i++){
        res.push_back(xe[i]);
    }

    sort(res.begin(),res.end(),greater<int>());
    long long r = 0;
    for(int i=0;i<u+v+w;i++){
        r += res[i];
    }
    cout<<r;

}