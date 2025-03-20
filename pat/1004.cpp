#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector< vector<int> > tree(n+1);
    for(int i=0;i<m;i++){
        int root;
        int childrencnt;
        cin>>root>>childrencnt;
        vector<int> children(childrencnt);
        for(int j=0;j<childrencnt;j++){
            cin>>children[j];
        }
        tree[root] = children;

    }

    vector<int> res;

    queue<int> q;
    q.push(1);
    
    while(!q.empty()){
        int layer = q.size();
        int layercnt = 0;
        for(int i=0;i<layer;i++){
            int topp = q.front();
            q.pop();
            if(tree[topp].size() == 0){
                layercnt++;
            }else{
                for(int it:tree[topp]){
                    q.push(it);
                }
            }
        }
        res.push_back(layercnt);
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