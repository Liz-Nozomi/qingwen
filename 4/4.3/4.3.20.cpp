#include <bits/stdc++.h>
using namespace std;
int n;

vector< vector<int> >res;
vector<int> templ;


void DFS(int currentPos){
    if(currentPos>n){
        res.push_back(templ);   
        return;
    }
    DFS(currentPos+1);
    templ.push_back(currentPos);
    DFS(currentPos+1);
    templ.pop_back();

}


bool cmp(vector<int> &v1,vector<int> &v2){
    if(v1.size()!=v2.size()){
        return v1.size()<v2.size();
    }
    else{
    return v1<v2;
    }
    
}

int main(){
    cin>>n;
    DFS(1);
    sort(res.begin(),res.end(),cmp);
    
    for(auto it:res){
        int t=0;
        for(auto it2:it){

            cout<<it2;
            t++;
            if(t<it.size()){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    

}