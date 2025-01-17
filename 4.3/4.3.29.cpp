#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<string> res;
string line,sr;
map<char,bool> used;

void DFS(int currentcount){
    if(currentcount == sr.length() ){
        res.push_back(line);
        return;
    }

    for(int i=0;i<sr.length();i++){
        if(used[sr[i]] != 1){
            line.push_back(sr[i]);
            used[sr[i]]=true;
            DFS(currentcount+1);
            used[sr[i]]=false;
            line.pop_back();
        }
        
    }

}



int main(){
    
    cin>>sr;

    DFS(0);

    sort(res.begin(),res.end());
    
    //output
    for(auto it:res){
        int t=0;
        for(auto it2:it){

            cout<<it2;
            t++;
            if(t<it.size()){
                //cout<<" ";
            }
        }
        cout<<endl;
    }
}