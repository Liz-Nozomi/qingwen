#include <bits/stdc++.h>
using namespace std;


int main(){
    int n=0,m=0;
    cin>>n>>m;
    vector<int> S,T;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        S.push_back(temp);

    }   
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        T.push_back(temp);

    }        
    sort(S.begin(),S.end());
    sort(T.begin(),T.end());

    int paircount=0;
    int j=0;
    
    for(int i=0;i<n;i++){
        while(S[i]>T[j] and j<m){
            j++;
        }
        if(S[i]<=T[j]){
        paircount++;
        cout<<S[i]<<T[j]<<endl;
        j++;
        }

    }
    cout<<paircount;

}