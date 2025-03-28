#include <bits/stdc++.h>
using namespace std;

struct node{
    int l,r;
};

node tree[51];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tree[i].l>>tree[i].r;
    }

    vector<bool> isroot(n,true);
    for(int i=0;i<n;i++){
        if(tree[i].l) isroot[tree[i].l] = false;
        if(tree[i].r) isroot[tree[i].r] = false;

    }
    int root;
    for(int i=0;i<n;i++){
        if(isroot[i]){
            root = i;
        }
    }
    
    queue<int> q;
    q.push(root);
    vector<int> res;
    while(!q.empty()){
        int len = q.size();
        //layers
        res.push_back(q.front());
        for(int i=0;i<len;i++){
            int temp = q.front();
            q.pop();
            if(tree[temp].l != -1)q.push(tree[temp].l);
            if(tree[temp].r != -1)q.push(tree[temp].r);
            
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