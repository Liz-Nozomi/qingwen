#include <bits/stdc++.h>
using namespace std;

int n;

int findmaxpath(vector <vector<int> > &t,int a,int b){
    if(a==n-1){return t[a][b];}
    else{return(max(findmaxpath(t,a+1,b),findmaxpath(t,a+1,b+1))+t[a][b]);}
}

int main(){
    int depth=0;
    cin>>depth;
    n=depth;
    vector< vector<int> > tower;
    for(int i=0;i<n;i++){

        tower.push_back(vector<int>());

        for(int j=0;j<i+1;j++){
            int temp;
            cin>>temp;
            tower[i].push_back(temp);
            //cout<<temp;
        }
        
    }
    cout<<findmaxpath(tower,0,0);

}