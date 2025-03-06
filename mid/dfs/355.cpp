#include <bits/stdc++.h>
using namespace std;
struct node{
    int l = -1;
    int r = -1;
    int data;
};

void tpush(int num,vector<node> &tree){
    int next = 0;
    int prev = 0;
    bool tag;

    if(tree.size() == 0){
        node first;
        first.data = num;
        tree.push_back(first);
    }else{
    while(next != -1){
        if(num < tree[next].data){
            prev = next;
            next = tree[next].l;
            tag = 1;
        }
        else{
            prev = next;
            next = tree[next].r;
            tag = 0;
        }
    }//找到插入位置
    node ne;
    ne.data = num;
    tag?tree[prev].l = tree.size():tree[prev].r = tree.size();
    tree.push_back(ne);
}

}

void dfs(vector<int> &res,vector<node> &tree,int current){
    if(current == -1){
        return;
    }
    res.push_back(tree[current].data);
    dfs(res,tree,tree[current].l);
    dfs(res,tree,tree[current].r);

}


int main(){
    int n;
    cin>>n;
    vector<node> tree1;



    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        tpush(num,tree1);
    }

    vector<node> tree2;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        tpush(num,tree2);
    }
    
    vector<int> m1;
    vector<int> m2;
    dfs(m1,tree1,0);
    dfs(m2,tree2,0);
    cout<<(m1 == m2 ? "Yes" : "No");



}