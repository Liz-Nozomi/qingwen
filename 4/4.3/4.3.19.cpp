#include <bits/stdc++.h>
using namespace std;

int n;
vector< vector<int> > res;
vector<int> line;

void DFS(int depth){
    if(depth == n){
        res.push_back(line);
        return;
    }
    line.push_back(0);
    DFS(depth+1);
    line.pop_back();

    line.push_back(1);
    DFS(depth+1);
    line.pop_back();


}


int main(){
    cin>>n;
    DFS(0);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j];}
        cout<<endl;}


}