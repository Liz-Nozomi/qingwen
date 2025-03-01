#include <bits/stdc++.h>
using namespace std;

struct node{
    int l = -1;
    int r = -1;
    
    node(){}
};

void dfsadd(vector<node> &tree,int num,int root){
    if(num > root){
        if(tree[root].r == -1){
            tree[root].r = num;
        }
        else{dfsadd(tree,num,tree[root].r);}
    }else{
        if(tree[root].l == -1){
            tree[root].l = num;
        }else{
            dfsadd(tree,num,tree[root].l);
        }
    }
}

void dfs(vector<node> &tree,int root,vector<int> &res){
    if(tree[root].l != -1){
        dfs(tree,tree[root].l,res);
    }
    if(tree[root].r != -1){
        dfs(tree,tree[root].r,res);
    }
    
    res.push_back(root);

}

int main(){
    int n;
    cin>>n;
    
    vector<int> bst(n+1);

    for(int i=0;i<n;i++){
        cin>>bst[i];
    }
    int root = bst[0];

    vector<node> tree(105);
    
    for(int i=1;i<n;i++){
        dfsadd(tree,bst[i],root);
    }

    vector<int> res;
    dfs(tree,root,res);
    int temp = 0;
    for(auto it:res){
        cout<<it;
        temp++;
        if(temp < res.size()){
            cout<<" ";
        }
    }
}