#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> currentFile;
    unordered_map<string,vector<int> > fileSystem;
    vector<int> res;

    for(int i=0;i<n;i++){
        string op;
        cin>>op;
        if(op == "ADD"){
            int h;
            cin>>h;
            currentFile.push_back(h);
            res.push_back(h);
        }

        if(op == "DELETE"){
            if(currentFile.size() > 0){
                currentFile.pop_back();
            }
            if(currentFile.size() > 0){
                res.push_back(currentFile[currentFile.size()-1]);
            }else{
                res.push_back(-1);
            }

        }

        if(op == "SAVE"){
            string d;
            cin>>d;
            fileSystem[d] = currentFile;
            if(currentFile.size() > 0){
                res.push_back(currentFile[currentFile.size()-1]);
            }else{
                res.push_back(-1);
            }
        }

        if(op == "LOAD"){
            string d;
            cin>>d;
            currentFile = fileSystem[d];
            if(currentFile.size() > 0){
                res.push_back(currentFile[currentFile.size()-1]);
            }else{
                res.push_back(-1);
            }
        }
    }

    int temp = 0;
    for(auto it:res){
        cout<<it;
        temp++;
        if(temp < res.size()){
            cout<<" ";
        }
    }
}